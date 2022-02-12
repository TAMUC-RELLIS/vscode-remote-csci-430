#!/usr/bin/env bash
#
# Basic configuration, make sure box is up to date and add some
# generally useful packages like build-essential and python

# make sure initially everything up to date
apt -y update
apt -y dist-upgrade

# set time zone and hostname
timedatectl set-timezone America/Chicago
hostnamectl set-hostname devbox

# add some generally useful packages, like build tools, python and wget
#apt -y install build-essential csh wget htop sshfs python dos2unix git uncrustify doxygen graphviz texlive-base texlive-latex-extra texlive-latex-recommended
apt -y install build-essential gdb csh wget htop sshfs python dos2unix git uncrustify astyle doxygen graphviz clang-format

# set passwords for the default users
#passwd -d vagrant # this will remove the password
echo -e "ubuntu\nubuntu" | passwd ubuntu
echo -e "vagrant\nvagrant" | passwd vagrant

# set up basic LAMP server/services
#apt -y install apache2 mysql-server php libapache2-mod-php php-opcache php-cli php-gd php-curl php-mysql

# secure the mysql database a bit
#db_root_password="vagrant"
#mysql --user=root <<EOF
#  alter user 'root'@'localhost' identified by '${db_root_password}';
#  DELETE FROM mysql.user WHERE User='';
#  DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
#  DROP DATABASE IF EXISTS test;
#  DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';
#  FLUSH PRIVILEGES;
#EOF

# restart apache2 to get new configurations
#systemctl restart apache2 mysql


# install code-server
#curl -fsSL https://code-server.dev/install.sh | sh
echo "Download and install VSCode code-server"
cd /root
curl -fsSOL https://github.com/coder/code-server/releases/download/v4.0.1/code-server_4.0.1_amd64.deb
sudo dpkg -i code-server_4.0.1_amd64.deb
#curl -fsSOL https://github.com/cdr/code-server/releases/download/v3.9.3/code-server_3.9.3_amd64.deb
#sudo dpkg -i code-server_3.9.3_amd64.deb
systemctl enable --now code-server@vagrant
#rm code-server_3.9.3_amd64.deb
rm code-server_4.0.1_amd64.deb

# create private key for github/git repository access
echo "Setup ssh keys for developers"
su - vagrant -c "ssh-keygen -o -a 100 -t ed25519 -f ~/.ssh/id_ed25519 -C 'vagrant@devbox' -q -N '' "

cat > /home/vagrant/.ssh/config <<EOF
Host *
    StrictHostKeyChecking no
EOF
chown vagrant:vagrant /home/vagrant/.ssh/config

# make sure mounted file system is owned completely by vagrant user
echo "Setup and configure VS code-server"
chown -R vagrant:vagrant /home/vagrant/sync

# set up global keybindings for all code-server projects
mkdir -p /home/vagrant/.local/share/code-server/User
cat > /home/vagrant/.local/share/code-server/User/keybindings.json <<EOF
[
    {
        "key": "ctrl+shift+1",
        "command": "workbench.action.tasks.runTask",
        "when": "editorTextFocus",
        "args": "make clean"
    },
    {
        "key": "ctrl+shift+2",
        "command": "workbench.action.tasks.build",
        "when": "editorTextFocus"
    },
    {
        "key": "ctrl+shift+3",
        "command": "workbench.action.tasks.test",
        "when": "editorTextFocus"
    },
]
EOF
chown -R vagrant:vagrant /home/vagrant/.local

# get code-server extensions and install them
echo "Fetch VS-code server cpptools for later installation"
cd /home/vagrant

# lets try and get the latest release of cpptools-linux.  Requires a query on repo to
# do this
latest_release=`curl --silent "https://api.github.com/repos/microsoft/vscode-cpptools/releases/latest" | grep '"tag_name":' | sed -E 's/.*"([^"]+)".*/\1/'`
curl -fsSOL https://github.com/microsoft/vscode-cpptools/releases/download/$latest_release/cpptools-linux.vsix
chown vagrant:vagrant /home/vagrant/cpptools-linux.vsix

# restart the code server to ensure above changes are picked up
echo "Restart VS code-server so ready to use"
sed -i 's/bind-addr: 127.0.0.1:8080/bind-addr: 0.0.0.0:8080/' /home/vagrant/.config/code-server/config.yaml
sed -i 's/auth: password/auth: none/' /home/vagrant/.config/code-server/config.yaml
systemctl restart code-server@vagrant
