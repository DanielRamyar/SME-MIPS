﻿using System;
using SME;

namespace ALU
{
	[ClockedProcess]
	public class Tester : Process
	{
		[InputBus]
		Output output;
		[InputBus]
		Zero zero;

		[OutputBus]
		InputA inputA;
		[OutputBus]
		InputB inputB;
		[OutputBus]
		ALUOp op;

		public async override System.Threading.Tasks.Task Run()
		{
			await ClockAsync();

			op.code = opcodes.add; // add
			inputA.data = 2;
			inputB.data = 2;
			await ClockAsync();
			System.Diagnostics.Debug.Assert(output.data == 4);
			System.Diagnostics.Debug.Assert(zero.val == false);

			op.code = opcodes.sub; // sub
			inputA.data = 2;
			inputB.data = 2;
			await ClockAsync();
			System.Diagnostics.Debug.Assert(output.data == 0);
			System.Diagnostics.Debug.Assert(zero.val == true);

			op.code = opcodes.and; // and
			inputA.data = 1;
			inputB.data = 1;
			await ClockAsync();
			System.Diagnostics.Debug.Assert(output.data == 1);
			System.Diagnostics.Debug.Assert(zero.val == false);

			op.code = opcodes.or; // or
			inputA.data = 2;
			inputB.data = 1;
			await ClockAsync();
			System.Diagnostics.Debug.Assert(output.data == 3);
			System.Diagnostics.Debug.Assert(zero.val == false);

			/*op.code = 0x2A; // slt
			inputA.data = 1;
			inputB.data = 2;
			await ClockAsync();
			System.Diagnostics.Debug.Assert(output.data == 1);
			System.Diagnostics.Debug.Assert(zero.val == false);

			op.code = 0x2A; // slt
			inputA.data = 3;
			inputB.data = 2;
			await ClockAsync();
			System.Diagnostics.Debug.Assert(output.data == 0);
			System.Diagnostics.Debug.Assert(zero.val == true);*/
		}
	}
}
