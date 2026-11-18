CS101 Topic 44: Pipelining — Complete Lecture Notes
Understanding how computer processors achieve high performance requires analyzing both the physical limits of hardware and the architectural strategies designed to overcome them. Topic 44 examines Pipelining, a fundamental technique in computer architecture that increases system performance by overlapping the execution phases of consecutive instructions.

1. Physical Limitations & The Throughput Imperative
To understand why pipelining is necessary, one must first examine the physical boundaries governing microprocessors.
The Speed of Light Constraint
Electrical signals travel through silicon and copper wires no faster than the speed of light, which is approximately 1 foot per nanosecond ($1\text{ nanosecond} = 10^{-9}\text{ seconds}$).
When the Central Processing Unit (CPU) reads an instruction from main memory located 1 foot away on the motherboard:

Transmission Delay: It takes at least 1 nanosecond for the read request signal to travel from the CPU to main memory.
Return Delay: It takes at least 1 nanosecond for the memory cell to transmit the requested instruction back to the CPU.

Thus, retrieving a single instruction requires a minimum of 2 nanoseconds solely for signal propagation, even before accounting for internal memory lookup delays or decoding. Completing an entire instruction cycle—comprising fetching, decoding, and executing—naturally requires several nanoseconds.
Execution Speed vs. Throughput
Because signal propagation speeds cannot exceed physical laws, simply boosting the processor's internal clock speed encounters hardware and thermal limitations. Computer architects address this by distinguishing between two core performance metrics:

Execution Speed: The latency or total time required to complete one individual instruction from start to finish.
Throughput: The total volume of work (or total number of instructions) a computer system completes within a specified period of time.

Pipelining focuses entirely on maximizing throughput. It does not make an individual instruction complete faster; rather, it allows the processor to complete significantly more instructions per unit of time.

2. Core Mechanics of Pipelining
In a standard CPU architecture, instruction processing is divided into three sequential steps that form the Machine Cycle:

Fetch: Retrieving the instruction bit pattern from main memory into the Instruction Register.
Decode: Interpreting the opcode and operands within the Control Unit.
Execute: Activating the relevant circuitry in the Arithmetic/Logic Unit (ALU) or register unit to perform the operation.

Overlapping the Machine Cycle
Without pipelining, the CPU must complete all three stages of an instruction before fetching the next one. This leaves major sub-components of the processor idle during two-thirds of the processing timeline.
Pipelining restructures this workflow by allowing the operational steps of adjacent instructions to overlap. As soon as Instruction 1 finishes the Fetch stage and moves to the Decode stage, the Fetch hardware becomes free to retrieve Instruction 2.
Pipelined Execution Model:
Stage 1 (Fetch)   : [ Inst 3 ] -> [ Inst 2 ] -> [ Inst 1 ]
Stage 2 (Decode)  :               [ Inst 2 ] -> [ Inst 1 ]
Stage 3 (Execute) :                             [ Inst 1 ]

At any given moment, multiple instructions reside inside "the pipe" at different stages of completion.

3. Comparative Execution Analysis: 5-Instruction Benchmark
To quantify the efficiency gain achieved by pipelining, consider executing a sequence of 5 standard instructions, where each stage (Fetch, Decode, Execute) requires 1 time unit (e.g., 1 nanosecond).
Non-Pipelined Sequential Execution
Without pipelining, each instruction takes 3 complete time units. The CPU processes instructions sequentially from start to finish.
Time UnitInstruction 1Instruction 2Instruction 3Instruction 4Instruction 5$T_1$ – $T_3$Fetch $\rightarrow$ Decode $\rightarrow$ Execute$T_4$ – $T_6$Fetch $\rightarrow$ Decode $\rightarrow$ Execute$T_7$ – $T_9$Fetch $\rightarrow$ Decode $\rightarrow$ Execute$T_{10}$ – $T_{12}$Fetch $\rightarrow$ Decode $\rightarrow$ Execute$T_{13}$ – $T_{15}$Fetch $\rightarrow$ Decode $\rightarrow$ Execute
$$\text{Total Non-Pipelined Time} = 5 \text{ instructions} \times 3 \text{ time units} = \mathbf{15\text{ time units}}$$
Pipelined Overlapped Execution
With pipelining, a new instruction enters the pipeline every single time unit once the initial pipeline is filled.
Time Unit ($T$)Fetch StageDecode StageExecute StageActive Pipeline State$T_1$Instruction 1——Filling pipeline$T_2$Instruction 2Instruction 1—Filling pipeline$T_3$Instruction 3Instruction 2Instruction 1 (Done)Pipeline Full$T_4$Instruction 4Instruction 3Instruction 2 (Done)Steady State$T_5$Instruction 5Instruction 4Instruction 3 (Done)Steady State$T_6$—Instruction 5Instruction 4 (Done)Draining pipeline$T_7$——Instruction 5 (Done)Draining pipeline
$$\text{Total Pipelined Time} = \mathbf{7\text{ time units}}$$
Performance Comparison Matrix
MetricSequential ProcessingPipelined ProcessingGain / AdvantageExecution Time (5 Inst.)15 Time Units7 Time Units53.3% Reduction in Total TimeCompletion Rate (Steady State)1 instruction per 3 time units1 instruction per 1 time unit$3\times$ Increase in ThroughputHardware Utilization33% of execution sub-units activeUp to 100% active during steady stateMaximizes internal functional block efficiency

4. Pipeline Hazards: The JUMP Instruction Challenge
While pipelining significantly boosts processing speed, it introduces architectural challenges, most notably when dealing with Control Instructions (such as JUMP or conditional branches).
The Invalidation Problem (Pipeline Stall / Flush)

Pre-fetching Assumptions: Under normal sequential flow, the CPU assumes the next instruction to execute is the one located at the consecutive memory address. It automatically fetches $N+1$ while decoding $N$.
Branching Disruptions: When the CPU decodes and executes a JUMP instruction, the control unit may change the Program Counter to a completely different memory address (e.g., jumping from address A4 to F0).
Pipeline Invalidation: The instructions that were speculatively fetched into the pipeline during $T_2$ and $T_3$ are no longer the correct instructions. The processor must discard (flush) these invalid instructions from "the pipe" and restart the fetch cycle from the new branch target address.

As a result, frequent branching causes temporary losses in throughput advantage because time cycles are spent clearing and refilling the pipeline.

5. Modern Extensions: Superscalar & Parallel Execution
Contemporary multi-core microprocessors build upon basic pipelining principles to achieve even greater parallel performance.
1. Parallel Instruction Fetching
Rather than fetching a single instruction per cycle, modern fetch units retrieve multiple consecutive instructions simultaneously from high-speed cache memory into expanded instruction buffers.
2. Independent Superscalar Execution
Modern processor cores contain multiple specialized hardware execution units, such as:

Multiple Integer Arithmetic/Logic Units (ALUs)
Floating-Point Units (FPUs)
Load/Store Memory Units

If the CPU determines that adjacent instructions are non-interdependent (meaning neither instruction requires the result of the other), it dispatches them to different hardware execution units to be executed simultaneously in parallel during the exact same clock cycle.

6. Summary & Key Takeaways

Physical Constraint: Signal speeds are capped by the speed of light (~1 ft/ns), making instruction fetch latency unavoidable.
Throughput Focus: Pipelining targets throughput (total completed operations over time) rather than reducing the raw latency of a single instruction.
Overlapped Stages: By overlapping Fetch, Decode, and Execute phases across consecutive instructions, a 5-instruction task drops from 15 time units to 7 time units.
Pipeline Hazards: JUMP and conditional branch instructions can invalidate pre-fetched pipeline contents, requiring pipeline flushes.
Modern CPU Scaling: Advanced processors pair pipelining with parallel fetching and superscalar execution to run independent instructions simultaneously across multiple hardware execution units.
