	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	subq	$4000080, %rsp          ## imm = 0x3D0950
	movq	__ZNSt3__13cinE@GOTPCREL(%rip), %rdi
	leaq	-4000024(%rbp), %rsi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -4000020(%rbp)
	callq	__ZNSt3__113basic_istreamIcNS_11char_traitsIcEEErsERi
	xorl	%esi, %esi
	movl	$4000000, %ecx          ## imm = 0x3D0900
	movl	%ecx, %edx
	leaq	-4000016(%rbp), %rdi
	movq	%rax, -4000048(%rbp)    ## 8-byte Spill
	callq	_memset
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-4000024(%rbp), %eax
	movl	%eax, %ecx
	addl	$-1, %ecx
	movl	%ecx, -4000024(%rbp)
	cmpl	$0, %eax
	je	LBB0_5
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movq	__ZNSt3__13cinE@GOTPCREL(%rip), %rdi
	leaq	-4000028(%rbp), %rsi
	callq	__ZNSt3__113basic_istreamIcNS_11char_traitsIcEEErsERi
	movslq	-4000028(%rbp), %rsi
	cmpl	$0, -4000016(%rbp,%rsi,4)
	movq	%rax, -4000056(%rbp)    ## 8-byte Spill
	jle	LBB0_4
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	movslq	-4000028(%rbp), %rax
	movl	-4000016(%rbp,%rax,4), %ecx
	addl	$-1, %ecx
	movl	%ecx, -4000016(%rbp,%rax,4)
LBB0_4:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	-4000028(%rbp), %eax
	subl	$1, %eax
	movslq	%eax, %rcx
	movl	-4000016(%rbp,%rcx,4), %eax
	addl	$1, %eax
	movl	%eax, -4000016(%rbp,%rcx,4)
	jmp	LBB0_1
LBB0_5:
	movl	$0, -4000032(%rbp)
	movl	$0, -4000036(%rbp)
LBB0_6:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$1000000, -4000036(%rbp) ## imm = 0xF4240
	jge	LBB0_9
## BB#7:                                ##   in Loop: Header=BB0_6 Depth=1
	movslq	-4000036(%rbp), %rax
	movl	-4000016(%rbp,%rax,4), %ecx
	addl	-4000032(%rbp), %ecx
	movl	%ecx, -4000032(%rbp)
## BB#8:                                ##   in Loop: Header=BB0_6 Depth=1
	movl	-4000036(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4000036(%rbp)
	jmp	LBB0_6
LBB0_9:
	movq	__ZNSt3__14coutE@GOTPCREL(%rip), %rdi
	movl	-4000032(%rbp), %esi
	callq	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
	movl	-4000020(%rbp), %esi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rdi
	movq	(%rdi), %rdi
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rdi
	movq	%rax, -4000064(%rbp)    ## 8-byte Spill
	movl	%esi, -4000068(%rbp)    ## 4-byte Spill
	jne	LBB0_11
## BB#10:
	movl	-4000068(%rbp), %eax    ## 4-byte Reload
	addq	$4000080, %rsp          ## imm = 0x3D0950
	popq	%rbp
	retq
LBB0_11:
	callq	___stack_chk_fail
	.cfi_endproc


.subsections_via_symbols
