#pragma once
#include <roblox/miscellaneous/structures/encryptions.h>
#include <roblox/miscellaneous/storage/storage.h>
#include <roblox/miscellaneous/structures/teb.h>

#define VM_SHUFFLE2(s, a1, a2) a1 s a2
#define VM_SHUFFLE3(s, a1, a2, a3) a2 s a1 s a3
#define VM_SHUFFLE4(s, a1, a2, a3, a4) a2 s a1 s a4 s a3 
#define VM_SHUFFLE5(s, a1, a2, a3, a4, a5) a3 s a4 s a2 s a5 s a1
#define VM_SHUFFLE6(s, a1, a2, a3, a4, a5, a6) a1 s a4 s a6 s a3 s a2 s a5
#define VM_SHUFFLE7(s, a1, a2, a3, a4, a5, a6, a7) a7 s a2 s a6 s a3 s a5 s a4 s a1
#define VM_SHUFFLE9(s, a1, a2, a3, a4, a5, a6, a7, a8, a9) a4 s a7 s a8 s a6 s a1 s a9 s a5 s a3 s a2

/* tstring */
#define tHashEnc vmvalue1
#define tLenEnc vmvalue3

/* udata */
#define uMetatableEnc vmvalue3

/* proto */
#define pMember1Enc vmvalue3
#define pMember2Enc vmvalue2
#define pDebugNameEnc vmvalue3
#define pDebugInsnEnc vmvalue4
#define pTypeInfoEnc vmvalue2

/* closure */
#define cFuncEnc vmvalue1
#define cContEnc vmvalue3
#define cDebugNameEnc vmvalue4

/* table */
#define tMetatableEnc vmvalue1
#define tArrayEnc vmvalue1
#define tNodeEnc vmvalue1

/* global */
#define gTtnameEnc vmvalue1
#define gTmnameEnc vmvalue1

/* lua state */
#define lGlobalEnc vmvalue4
#define lStackSizeEnc vmvalue4

namespace module {
	enum offsets : std::intptr_t {
		/* TaskScheduler */
		schedulerJobName = 16,
		schedulerFps = 280,
		schedulerJobStart = 308,
		schedulerJobEnd = 312,

		/* ScriptJob */
		scriptJobDataModel = 40,
		scriptJobScriptContext = 304,

		/* datamodel */
		datamodelGameId = 1088,

		/* PropertyDescriptor */
		propertyDescriptorName = 4,
		propertyDescriptorScriptable = 48,

		/* ClassDescriptor */
		classDescriptorClassName = 4,
		classDescriptorProperties = 24,

		/* Instance */
		instanceClassDescriptor = 12,

		/* Script */
		moduleScriptBytecode = 292,
		localScriptBytecode = 320,

        /* extraSpace */
        scriptPtr = 52,

        /* BasePart */
		partTouchPrimitive = 216,
		partTouchTransmitter = 388,

		/* Signals */
		signalNext = 16,
		signalRefIdx = 8,
		signalState = 20,
		signalRef0 = 72,
		signalRef1 = 100,

		/* others */
		identityImpersonator = 216,
	};
};