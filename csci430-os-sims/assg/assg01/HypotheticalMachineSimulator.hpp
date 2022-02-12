/** @file HypotheticalMachineSimulator.hpp
 * @brief HypotheticalMachineSimulator API/Includes
 *
 * @author Jane Programmer
 * @note   cwid: 123456
 * @date   Fall 2020
 * @note   ide:  VS Code Editor/IDE ; GNU gcc tools
 *
 * Header include file for our Hypothetical machine class.
 * Definition of simulator API goes in this file.  Implementation
 * of member methods is found in corresponding .cpp file.
 */
#ifndef HYPOTHETICAL_MACHINE_SIMULATOR_HPP
#define HYPOTHETICAL_MACHINE_SIMULATOR_HPP
#include "SimulatorException.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>

using namespace std;

/** @enum OpcodeMnemonic
 * @brief opcode mnemonic codes
 *
 * opcode mnemonic codes for the hypothetical machine simulator
 * and overloaded output stream operator to display opcodes
 * to a stream in more human friendly forms.
 */
enum OpcodeMnemonic
{
  NOOP_HALT = 0,
  LOAD = 1,
  STORE = 2,
  JMP = 3,
  SUB = 4,
  ADD = 5
};
ostream& operator<<(ostream& out, const OpcodeMnemonic& opcode);

/** @class HypotheticalMachineSimulator
 * @brief Hypothetical Machine Simulation class
 *
 * Perform simulation of the Stallings 7th ed. hypothetical machine.
 * This simulator can read in initial state of a hypothetical machine,
 * the registers (PC program counter, AC accumulator) and initial
 * memory contents, which may include code and data.  Functions are
 * provided to simulate fetch/execute cycles for the hypothetical
 * machine, and support functions to implement the different
 * supported operation opcodes of the machine (like memory peek/poke).
 */
class HypotheticalMachineSimulator
{
private:
  /// @brief An array of memory contents for our hypothetical machine
  int* memory;
  /// @brief Base address of simulated memory
  int memoryBaseAddress;
  /// @brief Bounding address (end) of simulated memory
  int memoryBoundsAddress;
  /// @brief Total size of simulated memory in machine
  int memorySize;
  /// @brief Program Counter register
  int pc;
  /// @brief Accumulator register
  int ac;
  /// @brief Instruction register
  int ir;
  /// @brief Translated opcode of current instruction
  OpcodeMnemonic irOpcode;
  /// @brief Translated reference address of current instruction
  int irAddress;
  /// @brief List of memory locations when displaying system state
  list<int> memoryAddressList;

public:
  // constructors and destructors
  HypotheticalMachineSimulator();
  ~HypotheticalMachineSimulator();
  void reset();

  // program loading and initializtion
  void loadProgram(string simulationFile);
  void initializeMemory(int memoryBaseAddress, int memoryBoundsAddress);

  // program execution
  int translateAddress(int virtAddr) const;
  void pokeAddress(int simAddr, int value);
  int peekAddress(int simAddr) const;
  void fetch();
  void execute();
  void executeLoad();
  void executeStore();
  void executeAdd();
  void executeSub();
  void executeJmp();
  int runSimulation(int maxCycles = 100, bool verbose = false);

  // accessor methods, mostly for testing
  int getMemoryBaseAddress() const;
  int getMemoryBoundsAddress() const;
  int getMemorySize() const;
  int getPC() const;
  void incrementPC();
  int getAC() const;
  int getIR() const;
  int getIROpcode() const;
  int getIRAddress() const;

  // overloaded operators
  friend ostream& operator<<(ostream& out, const HypotheticalMachineSimulator& sim);
};

#endif // HYPOTHETICAL_MACHINE_SIMULATOR_HPP