
putchar.coff:     format de fichier ecoff-littlemips

Déassemblage de la section .text:

00000000 <_ftext>:
   0:	ffffffff 	0xffffffff
   4:	ffffffff 	0xffffffff
	...

00000080 <__start>:
  80:	0c000343 	jal	d0c <main>
  84:	00000000 	nop
  88:	0c00002a 	jal	a8 <Exit>
  8c:	00002021 	move	r4,r0
  90:	ffffffff 	0xffffffff
  94:	ffffffff 	0xffffffff

00000098 <Halt>:
  98:	24020000 	li	r2,0
  9c:	0000000c 	syscall
  r4:	03e00008 	jr	r31
  a4:	00000000 	nop

000000a8 <Exit>:
  a8:	24020001 	li	r2,1
  ac:	0000000c 	syscall
  b0:	03e00008 	jr	r31
  b4:	00000000 	nop

000000b8 <Exec>:
  b8:	24020002 	li	r2,2
  bc:	0000000c 	syscall
  c0:	03e00008 	jr	r31
  c4:	00000000 	nop

000000c8 <Join>:
  c8:	24020003 	li	r2,3
  cc:	0000000c 	syscall
  d0:	03e00008 	jr	r31
  d4:	00000000 	nop

000000d8 <Create>:
  d8:	24020004 	li	r2,4
  dc:	0000000c 	syscall
  e0:	03e00008 	jr	r31
  e4:	00000000 	nop

000000e8 <Open>:
  e8:	24020005 	li	r2,5
  ec:	0000000c 	syscall
  f0:	03e00008 	jr	r31
  f4:	00000000 	nop

000000f8 <Read>:
  f8:	24020006 	li	r2,6
  fc:	0000000c 	syscall
 100:	03e00008 	jr	r31
 104:	00000000 	nop

00000108 <Write>:
 108:	24020007 	li	r2,7
 10c:	0000000c 	syscall
 110:	03e00008 	jr	r31
 114:	00000000 	nop

00000118 <Close>:
 118:	24020008 	li	r2,8
 11c:	0000000c 	syscall
 120:	03e00008 	jr	r31
 124:	00000000 	nop

00000128 <Fork>:
 128:	24020009 	li	r2,9
 12c:	0000000c 	syscall
 130:	03e00008 	jr	r31
 134:	00000000 	nop

00000138 <Yield>:
 138:	2402000a 	li	r2,10
 13c:	0000000c 	syscall
 140:	03e00008 	jr	r31
 144:	00000000 	nop

00000148 <PutChar>:
 148:	2402000b 	li	r2,11
 14c:	0000000c 	syscall
 150:	03e00008 	jr	r31
 154:	00000000 	nop

00000158 <PutString>:
 158:	2402000d 	li	r2,13
 15c:	0000000c 	syscall
 160:	03e00008 	jr	r31
 164:	00000000 	nop

00000168 <PutInt>:
 168:	2402000f 	li	r2,15
 16c:	0000000c 	syscall
 170:	03e00008 	jr	r31
 174:	00000000 	nop

00000178 <GetChar>:
 178:	2402000c 	li	r2,12
 17c:	0000000c 	syscall
 180:	03e00008 	jr	r31
 184:	00000000 	nop

00000188 <GetString>:
 188:	2402000e 	li	r2,14
 18c:	0000000c 	syscall
 190:	03e00008 	jr	r31
 194:	00000000 	nop

00000198 <GetInt>:
 198:	24020010 	li	r2,16
 19c:	0000000c 	syscall
 1a0:	03e00008 	jr	r31
 1a4:	00000000 	nop

000001a8 <__main>:
 1a8:	03e00008 	jr	r31
 1ac:	00000000 	nop

000001b0 <strnlen>:
 1b0:	00801821 	move	r3,r4
 1b4:	10a0000c 	beqz	r5,1e8 <strnlen+0x38>
 1b8:	24a6ffff 	addiu	r6,r5,-1
 1bc:	80820000 	lb	r2,0(r4)
 1c0:	00000000 	nop
 1c4:	10400008 	beqz	r2,1e8 <strnlen+0x38>
 1c8:	2405ffff 	li	r5,-1
 1cc:	24c6ffff 	addiu	r6,r6,-1
 1d0:	10c50005 	beq	r6,r5,1e8 <strnlen+0x38>
 1d4:	24630001 	addiu	r3,r3,1
 1d8:	80620000 	lb	r2,0(r3)
 1dc:	00000000 	nop
 1e0:	1440fffb 	bnez	r2,1d0 <strnlen+0x20>
 1e4:	24c6ffff 	addiu	r6,r6,-1
 1e8:	03e00008 	jr	r31
 1ec:	00641023 	subu	r2,r3,r4

000001f0 <simple_strtoul>:
 1f0:	00804821 	move	t1,r4
 1f4:	3c040000 	lui	r4,0x0
 1f8:	24840f70 	addiu	r4,r4,3952
 1fc:	14c00014 	bnez	r6,250 <simple_strtoul+0x60>
 200:	00005021 	move	t2,r0
 204:	81230000 	lb	r3,0(t1)
 208:	24020030 	li	r2,48
 20c:	14620010 	bne	r3,r2,250 <simple_strtoul+0x60>
 210:	2406000a 	li	r6,10
 214:	25290001 	addiu	t1,t1,1
 218:	81230000 	lb	r3,0(t1)
 21c:	24020078 	li	r2,120
 220:	1462000b 	bne	r3,r2,250 <simple_strtoul+0x60>
 224:	24060008 	li	r6,8
 228:	91220001 	lbu	r2,1(t1)
 22c:	00000000 	nop
 230:	00441021 	addu	r2,r2,r4
 234:	90430000 	lbu	r3,0(r2)
 238:	00000000 	nop
 23c:	30630044 	andi	r3,r3,0x44
 240:	10600003 	beqz	r3,250 <simple_strtoul+0x60>
 244:	00000000 	nop
 248:	25290001 	addiu	t1,t1,1
 24c:	24060010 	li	r6,16
 250:	91270000 	lbu	r7,0(t1)
 254:	00805821 	move	t3,r4
 258:	00eb1821 	addu	r3,r7,t3
 25c:	90620000 	lbu	r2,0(r3)
 260:	00000000 	nop
 264:	30420044 	andi	r2,r2,0x44
 268:	10400028 	beqz	r2,30c <simple_strtoul+0x11c>
 26c:	00000000 	nop
 270:	01606021 	move	t4,t3
 274:	00ec1021 	addu	r2,r7,t4
 278:	90420000 	lbu	r2,0(r2)
 27c:	00000000 	nop
 280:	30430004 	andi	r3,r2,0x4
 284:	10600005 	beqz	r3,29c <simple_strtoul+0xac>
 288:	30420002 	andi	r2,r2,0x2
 28c:	00071600 	sll	r2,r7,0x18
 290:	00021603 	sra	r2,r2,0x18
 294:	080000b6 	j	2d8 <simple_strtoul+0xe8>
 298:	2448ffd0 	addiu	r8,r2,-48
 29c:	1040000c 	beqz	r2,2d0 <simple_strtoul+0xe0>
 2a0:	00071600 	sll	r2,r7,0x18
 2a4:	3c020000 	lui	r2,0x0
 2a8:	00471021 	addu	r2,r2,r7
 2ac:	90420f70 	lbu	r2,3952(r2)
 2b0:	00000000 	nop
 2b4:	30420002 	andi	r2,r2,0x2
 2b8:	10400003 	beqz	r2,2c8 <simple_strtoul+0xd8>
 2bc:	00e01821 	move	r3,r7
 2c0:	24e2ffe0 	addiu	r2,r7,-32
 2c4:	304300ff 	andi	r3,r2,0xff
 2c8:	080000b5 	j	2d4 <simple_strtoul+0xe4>
 2cc:	306200ff 	andi	r2,r3,0xff
 2d0:	00021603 	sra	r2,r2,0x18
 2d4:	2448ffc9 	addiu	r8,r2,-55
 2d8:	0106102b 	sltu	r2,r8,r6
 2dc:	1040000b 	beqz	r2,30c <simple_strtoul+0x11c>
 2e0:	01460018 	mult	t2,r6
 2e4:	25290001 	addiu	t1,t1,1
 2e8:	91270000 	lbu	r7,0(t1)
 2ec:	00000000 	nop
 2f0:	00eb1821 	addu	r3,r7,t3
 2f4:	90640000 	lbu	r4,0(r3)
 2f8:	00000000 	nop
 2fc:	30840044 	andi	r4,r4,0x44
 300:	00001012 	mflo	r2
 304:	1480ffdb 	bnez	r4,274 <simple_strtoul+0x84>
 308:	00485021 	addu	t2,r2,r8
 30c:	10a00002 	beqz	r5,318 <simple_strtoul+0x128>
 310:	00000000 	nop
 314:	aca90000 	sw	t1,0(r5)
 318:	03e00008 	jr	r31
 31c:	01401021 	move	r2,t2

00000320 <simple_strtol>:
 320:	27bdffe8 	addiu	r29,r29,-24
 324:	afbf0010 	sw	r31,16(r29)
 328:	80830000 	lb	r3,0(r4)
 32c:	2402002d 	li	r2,45
 330:	10620005 	beq	r3,r2,348 <simple_strtol+0x28>
 334:	00000000 	nop
 338:	0c00007c 	jal	1f0 <simple_strtoul>
 33c:	00000000 	nop
 340:	080000d5 	j	354 <simple_strtol+0x34>
 344:	00000000 	nop
 348:	0c00007c 	jal	1f0 <simple_strtoul>
 34c:	24840001 	addiu	r4,r4,1
 350:	00021023 	negu	r2,r2
 354:	8fbf0010 	lw	r31,16(r29)
 358:	00000000 	nop
 35c:	03e00008 	jr	r31
 360:	27bd0018 	addiu	r29,r29,24

00000364 <skip_atoi>:
 364:	00803821 	move	r7,r4
 368:	8ce50000 	lw	r5,0(r7)
 36c:	00000000 	nop
 370:	90a20000 	lbu	r2,0(r5)
 374:	00000000 	nop
 378:	2442ffd0 	addiu	r2,r2,-48
 37c:	2c42000a 	sltiu	r2,r2,10
 380:	1040000e 	beqz	r2,3bc <skip_atoi+0x58>
 384:	00003021 	move	r6,r0
 388:	24a30001 	addiu	r3,r5,1
 38c:	80a40000 	lb	r4,0(r5)
 390:	00602821 	move	r5,r3
 394:	00061080 	sll	r2,r6,0x2
 398:	00461021 	addu	r2,r2,r6
 39c:	00021040 	sll	r2,r2,0x1
 3a0:	ace30000 	sw	r3,0(r7)
 3a4:	90a30000 	lbu	r3,0(r5)
 3a8:	00441021 	addu	r2,r2,r4
 3ac:	2463ffd0 	addiu	r3,r3,-48
 3b0:	2c63000a 	sltiu	r3,r3,10
 3b4:	1460fff4 	bnez	r3,388 <skip_atoi+0x24>
 3b8:	2446ffd0 	addiu	r6,r2,-48
 3bc:	03e00008 	jr	r31
 3c0:	00c01021 	move	r2,r6

000003c4 <number>:
 3c4:	27bdffb8 	addiu	r29,r29,-72
 3c8:	3c0f0000 	lui	t7,0x0
 3cc:	25ef0d80 	addiu	t7,t7,3456
 3d0:	8fa3005c 	lw	r3,92(r29)
 3d4:	8faa0058 	lw	t2,88(r29)
 3d8:	30620040 	andi	r2,r3,0x40
 3dc:	10400003 	beqz	r2,3ec <number+0x28>
 3e0:	00804021 	move	r8,r4
 3e4:	3c0f0000 	lui	t7,0x0
 3e8:	25ef0da8 	addiu	t7,t7,3496
 3ec:	306b0010 	andi	t3,r3,0x10
 3f0:	11600002 	beqz	t3,3fc <number+0x38>
 3f4:	2402fffe 	li	r2,-2
 3f8:	00621824 	and	r3,r3,r2
 3fc:	24c2fffe 	addiu	r2,r6,-2
 400:	2c420023 	sltiu	r2,r2,35
 404:	14400003 	bnez	r2,414 <number+0x50>
 408:	30620001 	andi	r2,r3,0x1
 40c:	08000188 	j	620 <number+0x25c>
 410:	00001021 	move	r2,r0
 414:	10400002 	beqz	r2,420 <number+0x5c>
 418:	24180020 	li	t8,32
 41c:	24180030 	li	t8,48
 420:	30620002 	andi	r2,r3,0x2
 424:	1040000e 	beqz	r2,460 <number+0x9c>
 428:	00006821 	move	t5,r0
 42c:	04a10004 	bgez	r5,440 <number+0x7c>
 430:	30620004 	andi	r2,r3,0x4
 434:	240d002d 	li	t5,45
 438:	08000117 	j	45c <number+0x98>
 43c:	00052823 	negu	r5,r5
 440:	10400003 	beqz	r2,450 <number+0x8c>
 444:	30620008 	andi	r2,r3,0x8
 448:	08000117 	j	45c <number+0x98>
 44c:	240d002b 	li	t5,43
 450:	10400004 	beqz	r2,464 <number+0xa0>
 454:	306e0020 	andi	t6,r3,0x20
 458:	240d0020 	li	t5,32
 45c:	24e7ffff 	addiu	r7,r7,-1
 460:	306e0020 	andi	t6,r3,0x20
 464:	11c00008 	beqz	t6,488 <number+0xc4>
 468:	24020010 	li	r2,16
 46c:	14c20003 	bne	r6,r2,47c <number+0xb8>
 470:	24020008 	li	r2,8
 474:	08000122 	j	488 <number+0xc4>
 478:	24e7fffe 	addiu	r7,r7,-2
 47c:	14c20002 	bne	r6,r2,488 <number+0xc4>
 480:	00000000 	nop
 484:	24e7ffff 	addiu	r7,r7,-1
 488:	14a00007 	bnez	r5,4a8 <number+0xe4>
 48c:	00004821 	move	t1,r0
 490:	24020030 	li	r2,48
 494:	a3a20000 	sb	r2,0(r29)
 498:	24090001 	li	t1,1
 49c:	306b0010 	andi	t3,r3,0x10
 4a0:	0800013c 	j	4f0 <number+0x12c>
 4a4:	306c0011 	andi	t4,r3,0x11
 4a8:	306b0010 	andi	t3,r3,0x10
 4ac:	306c0011 	andi	t4,r3,0x11
 4b0:	00a6001b 	divu	r0,r5,r6
 4b4:	00001812 	mflo	r3
 4b8:	03a92021 	addu	r4,r29,t1
 4bc:	00001010 	mfhi	r2
 4c0:	14c00002 	bnez	r6,4cc <number+0x108>
 4c4:	00000000 	nop
 4c8:	0007000d 	break	0x7
 4cc:	14c00002 	bnez	r6,4d8 <number+0x114>
 4d0:	00000000 	nop
 4d4:	0007000d 	break	0x7
 4d8:	00602821 	move	r5,r3
 4dc:	01e21021 	addu	r2,t7,r2
 4e0:	90430000 	lbu	r3,0(r2)
 4e4:	25290001 	addiu	t1,t1,1
 4e8:	14a0fff1 	bnez	r5,4b0 <number+0xec>
 4ec:	a0830000 	sb	r3,0(r4)
 4f0:	0149102a 	slt	r2,t2,t1
 4f4:	10400002 	beqz	r2,500 <number+0x13c>
 4f8:	00000000 	nop
 4fc:	01205021 	move	t2,t1
 500:	00ea3823 	subu	r7,r7,t2
 504:	2544ffff 	addiu	r4,t2,-1
 508:	1580000a 	bnez	t4,534 <number+0x170>
 50c:	2539ffff 	addiu	t9,t1,-1
 510:	00e01021 	move	r2,r7
 514:	18400007 	blez	r2,534 <number+0x170>
 518:	24e7ffff 	addiu	r7,r7,-1
 51c:	24030020 	li	r3,32
 520:	a1030000 	sb	r3,0(r8)
 524:	25080001 	addiu	r8,r8,1
 528:	00e01021 	move	r2,r7
 52c:	1c40fffc 	bgtz	r2,520 <number+0x15c>
 530:	24e7ffff 	addiu	r7,r7,-1
 534:	11a00003 	beqz	t5,544 <number+0x180>
 538:	00000000 	nop
 53c:	a10d0000 	sb	t5,0(r8)
 540:	25080001 	addiu	r8,r8,1
 544:	11c0000d 	beqz	t6,57c <number+0x1b8>
 548:	24020008 	li	r2,8
 54c:	14c20004 	bne	r6,r2,560 <number+0x19c>
 550:	24020010 	li	r2,16
 554:	24020030 	li	r2,48
 558:	0800015e 	j	578 <number+0x1b4>
 55c:	a1020000 	sb	r2,0(r8)
 560:	14c20006 	bne	r6,r2,57c <number+0x1b8>
 564:	24020030 	li	r2,48
 568:	a1020000 	sb	r2,0(r8)
 56c:	91e30021 	lbu	r3,33(t7)
 570:	25080001 	addiu	r8,r8,1
 574:	a1030000 	sb	r3,0(r8)
 578:	25080001 	addiu	r8,r8,1
 57c:	15600009 	bnez	t3,5a4 <number+0x1e0>
 580:	01401021 	move	r2,t2
 584:	08000166 	j	598 <number+0x1d4>
 588:	00e01021 	move	r2,r7
 58c:	a1180000 	sb	t8,0(r8)
 590:	25080001 	addiu	r8,r8,1
 594:	00e01021 	move	r2,r7
 598:	1c40fffc 	bgtz	r2,58c <number+0x1c8>
 59c:	24e7ffff 	addiu	r7,r7,-1
 5a0:	01401021 	move	r2,t2
 5a4:	00805021 	move	t2,r4
 5a8:	0122102a 	slt	r2,t1,r2
 5ac:	10400008 	beqz	r2,5d0 <number+0x20c>
 5b0:	24e5ffff 	addiu	r5,r7,-1
 5b4:	24030030 	li	r3,48
 5b8:	a1030000 	sb	r3,0(r8)
 5bc:	25080001 	addiu	r8,r8,1
 5c0:	01401021 	move	r2,t2
 5c4:	0122102a 	slt	r2,t1,r2
 5c8:	1440fffb 	bnez	r2,5b8 <number+0x1f4>
 5cc:	254affff 	addiu	t2,t2,-1
 5d0:	01201021 	move	r2,t1
 5d4:	18400008 	blez	r2,5f8 <number+0x234>
 5d8:	03204821 	move	t1,t9
 5dc:	03a91021 	addu	r2,r29,t1
 5e0:	01202021 	move	r4,t1
 5e4:	90430000 	lbu	r3,0(r2)
 5e8:	2529ffff 	addiu	t1,t1,-1
 5ec:	a1030000 	sb	r3,0(r8)
 5f0:	1c80fffa 	bgtz	r4,5dc <number+0x218>
 5f4:	25080001 	addiu	r8,r8,1
 5f8:	00e01021 	move	r2,r7
 5fc:	18400007 	blez	r2,61c <number+0x258>
 600:	00a03821 	move	r7,r5
 604:	24030020 	li	r3,32
 608:	a1030000 	sb	r3,0(r8)
 60c:	25080001 	addiu	r8,r8,1
 610:	00e01021 	move	r2,r7
 614:	1c40fffc 	bgtz	r2,608 <number+0x244>
 618:	24e7ffff 	addiu	r7,r7,-1
 61c:	01001021 	move	r2,r8
 620:	03e00008 	jr	r31
 624:	27bd0048 	addiu	r29,r29,72

00000628 <_vsnprintf>:
 628:	27bdffc0 	addiu	r29,r29,-64
 62c:	afb20020 	sw	s2,32(r29)
 630:	00e09021 	move	s2,r7
 634:	afb00018 	sw	s0,24(r29)
 638:	afa40040 	sw	r4,64(r29)
 63c:	00808021 	move	s0,r4
 640:	afbf003c 	sw	r31,60(r29)
 644:	afbe0038 	sw	r30,56(r29)
 648:	afb70034 	sw	s7,52(r29)
 64c:	afb60030 	sw	s6,48(r29)
 650:	afb5002c 	sw	s5,44(r29)
 654:	afb40028 	sw	s4,40(r29)
 658:	afb30024 	sw	s3,36(r29)
 65c:	afb1001c 	sw	s1,28(r29)
 660:	afa60048 	sw	r6,72(r29)
 664:	80c20000 	lb	r2,0(r6)
 668:	00000000 	nop
 66c:	1040013d 	beqz	r2,b64 <_vsnprintf+0x53c>
 670:	00a0f021 	move	r30,r5
 674:	2402ffff 	li	r2,-1
 678:	13c20003 	beq	r30,r2,688 <_vsnprintf+0x60>
 67c:	00000000 	nop
 680:	1bc00138 	blez	r30,b64 <_vsnprintf+0x53c>
 684:	00000000 	nop
 688:	8fa20048 	lw	r2,72(r29)
 68c:	24040025 	li	r4,37
 690:	80430000 	lb	r3,0(r2)
 694:	90420000 	lbu	r2,0(r2)
 698:	146400ee 	bne	r3,r4,a54 <_vsnprintf+0x42c>
 69c:	0000a021 	move	s4,r0
 6a0:	8fa40048 	lw	r4,72(r29)
 6a4:	00000000 	nop
 6a8:	24830001 	addiu	r3,r4,1
 6ac:	afa30048 	sw	r3,72(r29)
 6b0:	90820001 	lbu	r2,1(r4)
 6b4:	00000000 	nop
 6b8:	2442ffe0 	addiu	r2,r2,-32
 6bc:	00021600 	sll	r2,r2,0x18
 6c0:	00021603 	sra	r2,r2,0x18
 6c4:	2c430011 	sltiu	r3,r2,17
 6c8:	10600011 	beqz	r3,710 <_vsnprintf+0xe8>
 6cc:	00021080 	sll	r2,r2,0x2
 6d0:	3c030000 	lui	r3,0x0
 6d4:	00621821 	addu	r3,r3,r2
 6d8:	8c630dd8 	lw	r3,3544(r3)
 6dc:	00000000 	nop
 6e0:	00600008 	jr	r3
 6e4:	00000000 	nop
 6e8:	080001a8 	j	6a0 <_vsnprintf+0x78>
 6ec:	36940010 	ori	s4,s4,0x10
 6f0:	080001a8 	j	6a0 <_vsnprintf+0x78>
 6f4:	36940004 	ori	s4,s4,0x4
 6f8:	080001a8 	j	6a0 <_vsnprintf+0x78>
 6fc:	36940008 	ori	s4,s4,0x8
 700:	080001a8 	j	6a0 <_vsnprintf+0x78>
 704:	36940020 	ori	s4,s4,0x20
 708:	080001a8 	j	6a0 <_vsnprintf+0x78>
 70c:	36940001 	ori	s4,s4,0x1
 710:	8fa40048 	lw	r4,72(r29)
 714:	00000000 	nop
 718:	90830000 	lbu	r3,0(r4)
 71c:	00000000 	nop
 720:	2462ffd0 	addiu	r2,r3,-48
 724:	2c42000a 	sltiu	r2,r2,10
 728:	10400005 	beqz	r2,740 <_vsnprintf+0x118>
 72c:	2413ffff 	li	s3,-1
 730:	0c0000d9 	jal	364 <skip_atoi>
 734:	27a40048 	addiu	r4,r29,72
 738:	080001e1 	j	784 <_vsnprintf+0x15c>
 73c:	00409821 	move	s3,r2
 740:	00031600 	sll	r2,r3,0x18
 744:	00021603 	sra	r2,r2,0x18
 748:	2403002a 	li	r3,42
 74c:	1443000e 	bne	r2,r3,788 <_vsnprintf+0x160>
 750:	2416ffff 	li	s6,-1
 754:	26420003 	addiu	r2,s2,3
 758:	2403fffc 	li	r3,-4
 75c:	00431024 	and	r2,r2,r3
 760:	24520004 	addiu	s2,r2,4
 764:	24830001 	addiu	r3,r4,1
 768:	afa30048 	sw	r3,72(r29)
 76c:	8e53fffc 	lw	s3,-4(s2)
 770:	00000000 	nop
 774:	06610004 	bgez	s3,788 <_vsnprintf+0x160>
 778:	00000000 	nop
 77c:	00139823 	negu	s3,s3
 780:	36940010 	ori	s4,s4,0x10
 784:	2416ffff 	li	s6,-1
 788:	8fa20048 	lw	r2,72(r29)
 78c:	2403002e 	li	r3,46
 790:	80440000 	lb	r4,0(r2)
 794:	00000000 	nop
 798:	1483001b 	bne	r4,r3,808 <_vsnprintf+0x1e0>
 79c:	00402821 	move	r5,r2
 7a0:	24a20001 	addiu	r2,r5,1
 7a4:	afa20048 	sw	r2,72(r29)
 7a8:	90a30001 	lbu	r3,1(r5)
 7ac:	00000000 	nop
 7b0:	2462ffd0 	addiu	r2,r3,-48
 7b4:	2c42000a 	sltiu	r2,r2,10
 7b8:	10400005 	beqz	r2,7d0 <_vsnprintf+0x1a8>
 7bc:	00031600 	sll	r2,r3,0x18
 7c0:	0c0000d9 	jal	364 <skip_atoi>
 7c4:	27a40048 	addiu	r4,r29,72
 7c8:	080001fe 	j	7f8 <_vsnprintf+0x1d0>
 7cc:	0040b021 	move	s6,r2
 7d0:	00021603 	sra	r2,r2,0x18
 7d4:	2403002a 	li	r3,42
 7d8:	14430007 	bne	r2,r3,7f8 <_vsnprintf+0x1d0>
 7dc:	26420003 	addiu	r2,s2,3
 7e0:	2403fffc 	li	r3,-4
 7e4:	00431024 	and	r2,r2,r3
 7e8:	24520004 	addiu	s2,r2,4
 7ec:	24a30002 	addiu	r3,r5,2
 7f0:	afa30048 	sw	r3,72(r29)
 7f4:	8e56fffc 	lw	s6,-4(s2)
 7f8:	8fa50048 	lw	r5,72(r29)
 7fc:	06c10002 	bgez	s6,808 <_vsnprintf+0x1e0>
 800:	00000000 	nop
 804:	0000b021 	move	s6,r0
 808:	80a30000 	lb	r3,0(r5)
 80c:	24020068 	li	r2,104
 810:	10620006 	beq	r3,r2,82c <_vsnprintf+0x204>
 814:	2415ffff 	li	s5,-1
 818:	2402006c 	li	r2,108
 81c:	10620003 	beq	r3,r2,82c <_vsnprintf+0x204>
 820:	2402004c 	li	r2,76
 824:	14620006 	bne	r3,r2,840 <_vsnprintf+0x218>
 828:	00000000 	nop
 82c:	8fa20048 	lw	r2,72(r29)
 830:	00000000 	nop
 834:	80550000 	lb	s5,0(r2)
 838:	24420001 	addiu	r2,r2,1
 83c:	afa20048 	sw	r2,72(r29)
 840:	8fa20048 	lw	r2,72(r29)
 844:	00000000 	nop
 848:	90430000 	lbu	r3,0(r2)
 84c:	00000000 	nop
 850:	2463ffdb 	addiu	r3,r3,-37
 854:	00031e00 	sll	r3,r3,0x18
 858:	00031e03 	sra	r3,r3,0x18
 85c:	2c620054 	sltiu	r2,r3,84
 860:	10400086 	beqz	r2,a7c <_vsnprintf+0x454>
 864:	2417000a 	li	s7,10
 868:	00031080 	sll	r2,r3,0x2
 86c:	3c030000 	lui	r3,0x0
 870:	00621821 	addu	r3,r3,r2
 874:	8c630e20 	lw	r3,3616(r3)
 878:	00000000 	nop
 87c:	00600008 	jr	r3
 880:	00000000 	nop
 884:	32820010 	andi	r2,s4,0x10
 888:	14400008 	bnez	r2,8ac <_vsnprintf+0x284>
 88c:	26470003 	addiu	r7,s2,3
 890:	2673ffff 	addiu	s3,s3,-1
 894:	1a600005 	blez	s3,8ac <_vsnprintf+0x284>
 898:	24020020 	li	r2,32
 89c:	a2020000 	sb	r2,0(s0)
 8a0:	2673ffff 	addiu	s3,s3,-1
 8a4:	1e60fffd 	bgtz	s3,89c <_vsnprintf+0x274>
 8a8:	26100001 	addiu	s0,s0,1
 8ac:	2402fffc 	li	r2,-4
 8b0:	00e21024 	and	r2,r7,r2
 8b4:	24520004 	addiu	s2,r2,4
 8b8:	9243fffc 	lbu	r3,-4(s2)
 8bc:	2673ffff 	addiu	s3,s3,-1
 8c0:	a2030000 	sb	r3,0(s0)
 8c4:	1a600097 	blez	s3,b24 <_vsnprintf+0x4fc>
 8c8:	26100001 	addiu	s0,s0,1
 8cc:	24020020 	li	r2,32
 8d0:	a2020000 	sb	r2,0(s0)
 8d4:	2673ffff 	addiu	s3,s3,-1
 8d8:	1e60fffd 	bgtz	s3,8d0 <_vsnprintf+0x2a8>
 8dc:	26100001 	addiu	s0,s0,1
 8e0:	080002c9 	j	b24 <_vsnprintf+0x4fc>
 8e4:	00000000 	nop
 8e8:	26420003 	addiu	r2,s2,3
 8ec:	2403fffc 	li	r3,-4
 8f0:	00431024 	and	r2,r2,r3
 8f4:	24520004 	addiu	s2,r2,4
 8f8:	8e51fffc 	lw	s1,-4(s2)
 8fc:	00000000 	nop
 900:	16200004 	bnez	s1,914 <_vsnprintf+0x2ec>
 904:	02202021 	move	r4,s1
 908:	3c110000 	lui	s1,0x0
 90c:	26310dd0 	addiu	s1,s1,3536
 910:	02202021 	move	r4,s1
 914:	0c00006c 	jal	1b0 <strnlen>
 918:	02c02821 	move	r5,s6
 91c:	00402021 	move	r4,r2
 920:	2402ffff 	li	r2,-1
 924:	13c2000f 	beq	r30,r2,964 <_vsnprintf+0x33c>
 928:	32820010 	andi	r2,s4,0x10
 92c:	8fa20040 	lw	r2,64(r29)
 930:	00000000 	nop
 934:	02021823 	subu	r3,s0,r2
 938:	03c31023 	subu	r2,r30,r3
 93c:	0082102a 	slt	r2,r4,r2
 940:	14400008 	bnez	r2,964 <_vsnprintf+0x33c>
 944:	32820010 	andi	r2,s4,0x10
 948:	24620001 	addiu	r2,r3,1
 94c:	03c22023 	subu	r4,r30,r2
 950:	18800058 	blez	r4,ab4 <_vsnprintf+0x48c>
 954:	0093102a 	slt	r2,r4,s3
 958:	10400002 	beqz	r2,964 <_vsnprintf+0x33c>
 95c:	32820010 	andi	r2,s4,0x10
 960:	00809821 	move	s3,r4
 964:	1440000b 	bnez	r2,994 <_vsnprintf+0x36c>
 968:	02601021 	move	r2,s3
 96c:	0082102a 	slt	r2,r4,r2
 970:	10400008 	beqz	r2,994 <_vsnprintf+0x36c>
 974:	2673ffff 	addiu	s3,s3,-1
 978:	24030020 	li	r3,32
 97c:	a2030000 	sb	r3,0(s0)
 980:	26100001 	addiu	s0,s0,1
 984:	02601021 	move	r2,s3
 988:	0082102a 	slt	r2,r4,r2
 98c:	1440fffb 	bnez	r2,97c <_vsnprintf+0x354>
 990:	2673ffff 	addiu	s3,s3,-1
 994:	18800008 	blez	r4,9b8 <_vsnprintf+0x390>
 998:	2665ffff 	addiu	r5,s3,-1
 99c:	00801821 	move	r3,r4
 9a0:	92220000 	lbu	r2,0(s1)
 9a4:	26310001 	addiu	s1,s1,1
 9a8:	2463ffff 	addiu	r3,r3,-1
 9ac:	a2020000 	sb	r2,0(s0)
 9b0:	1460fffb 	bnez	r3,9a0 <_vsnprintf+0x378>
 9b4:	26100001 	addiu	s0,s0,1
 9b8:	02601021 	move	r2,s3
 9bc:	0082102a 	slt	r2,r4,r2
 9c0:	10400058 	beqz	r2,b24 <_vsnprintf+0x4fc>
 9c4:	00a09821 	move	s3,r5
 9c8:	24030020 	li	r3,32
 9cc:	a2030000 	sb	r3,0(s0)
 9d0:	26100001 	addiu	s0,s0,1
 9d4:	02601021 	move	r2,s3
 9d8:	0082102a 	slt	r2,r4,r2
 9dc:	1440fffb 	bnez	r2,9cc <_vsnprintf+0x3a4>
 9e0:	2673ffff 	addiu	s3,s3,-1
 9e4:	080002c9 	j	b24 <_vsnprintf+0x4fc>
 9e8:	00000000 	nop
 9ec:	2402ffff 	li	r2,-1
 9f0:	16620003 	bne	s3,r2,a00 <_vsnprintf+0x3d8>
 9f4:	26420003 	addiu	r2,s2,3
 9f8:	24130008 	li	s3,8
 9fc:	36940001 	ori	s4,s4,0x1
 a00:	2403fffc 	li	r3,-4
 a04:	00431024 	and	r2,r2,r3
 a08:	24520004 	addiu	s2,r2,4
 a0c:	02002021 	move	r4,s0
 a10:	24060010 	li	r6,16
 a14:	afb60010 	sw	s6,16(r29)
 a18:	afb40014 	sw	s4,20(r29)
 a1c:	8e45fffc 	lw	r5,-4(s2)
 a20:	080002c6 	j	b18 <_vsnprintf+0x4f0>
 a24:	02603821 	move	r7,s3
 a28:	2402006c 	li	r2,108
 a2c:	26420003 	addiu	r2,s2,3
 a30:	2403fffc 	li	r3,-4
 a34:	00431024 	and	r2,r2,r3
 a38:	24520004 	addiu	s2,r2,4
 a3c:	8fa40040 	lw	r4,64(r29)
 a40:	8e43fffc 	lw	r3,-4(s2)
 a44:	02041023 	subu	r2,s0,r4
 a48:	080002c9 	j	b24 <_vsnprintf+0x4fc>
 a4c:	ac620000 	sw	r2,0(r3)
 a50:	24020025 	li	r2,37
 a54:	a2020000 	sb	r2,0(s0)
 a58:	080002c9 	j	b24 <_vsnprintf+0x4fc>
 a5c:	26100001 	addiu	s0,s0,1
 a60:	080002ad 	j	ab4 <_vsnprintf+0x48c>
 a64:	24170008 	li	s7,8
 a68:	36940040 	ori	s4,s4,0x40
 a6c:	080002ad 	j	ab4 <_vsnprintf+0x48c>
 a70:	24170010 	li	s7,16
 a74:	080002ad 	j	ab4 <_vsnprintf+0x48c>
 a78:	36940002 	ori	s4,s4,0x2
 a7c:	24020025 	li	r2,37
 a80:	a2020000 	sb	r2,0(s0)
 a84:	8fa30048 	lw	r3,72(r29)
 a88:	00000000 	nop
 a8c:	80620000 	lb	r2,0(r3)
 a90:	90640000 	lbu	r4,0(r3)
 a94:	10400004 	beqz	r2,aa8 <_vsnprintf+0x480>
 a98:	26100001 	addiu	s0,s0,1
 a9c:	a2040000 	sb	r4,0(s0)
 aa0:	080002c9 	j	b24 <_vsnprintf+0x4fc>
 aa4:	26100001 	addiu	s0,s0,1
 aa8:	2462ffff 	addiu	r2,r3,-1
 aac:	080002c9 	j	b24 <_vsnprintf+0x4fc>
 ab0:	afa20048 	sw	r2,72(r29)
 ab4:	2402006c 	li	r2,108
 ab8:	12a2000d 	beq	s5,r2,af0 <_vsnprintf+0x4c8>
 abc:	24020068 	li	r2,104
 ac0:	16a2000b 	bne	s5,r2,af0 <_vsnprintf+0x4c8>
 ac4:	32820002 	andi	r2,s4,0x2
 ac8:	26420003 	addiu	r2,s2,3
 acc:	2403fffc 	li	r3,-4
 ad0:	00431024 	and	r2,r2,r3
 ad4:	24520004 	addiu	s2,r2,4
 ad8:	9645fffc 	lhu	r5,-4(s2)
 adc:	32820002 	andi	r2,s4,0x2
 ae0:	10400008 	beqz	r2,b04 <_vsnprintf+0x4dc>
 ae4:	00051400 	sll	r2,r5,0x10
 ae8:	080002c1 	j	b04 <_vsnprintf+0x4dc>
 aec:	00022c03 	sra	r5,r2,0x10
 af0:	26420003 	addiu	r2,s2,3
 af4:	2403fffc 	li	r3,-4
 af8:	00431024 	and	r2,r2,r3
 afc:	24520004 	addiu	s2,r2,4
 b00:	8e45fffc 	lw	r5,-4(s2)
 b04:	02002021 	move	r4,s0
 b08:	02e03021 	move	r6,s7
 b0c:	02603821 	move	r7,s3
 b10:	afb60010 	sw	s6,16(r29)
 b14:	afb40014 	sw	s4,20(r29)
 b18:	0c0000f1 	jal	3c4 <number>
 b1c:	00000000 	nop
 b20:	00408021 	move	s0,r2
 b24:	8fa20048 	lw	r2,72(r29)
 b28:	00000000 	nop
 b2c:	24430001 	addiu	r3,r2,1
 b30:	afa30048 	sw	r3,72(r29)
 b34:	80440001 	lb	r4,1(r2)
 b38:	00000000 	nop
 b3c:	10800009 	beqz	r4,b64 <_vsnprintf+0x53c>
 b40:	2402ffff 	li	r2,-1
 b44:	13c2fed0 	beq	r30,r2,688 <_vsnprintf+0x60>
 b48:	00000000 	nop
 b4c:	8fa30040 	lw	r3,64(r29)
 b50:	00000000 	nop
 b54:	02031023 	subu	r2,s0,r3
 b58:	005e102a 	slt	r2,r2,r30
 b5c:	1440feca 	bnez	r2,688 <_vsnprintf+0x60>
 b60:	00000000 	nop
 b64:	a2000000 	sb	r0,0(s0)
 b68:	8fa40040 	lw	r4,64(r29)
 b6c:	8fbf003c 	lw	r31,60(r29)
 b70:	8fbe0038 	lw	r30,56(r29)
 b74:	8fb70034 	lw	s7,52(r29)
 b78:	8fb60030 	lw	s6,48(r29)
 b7c:	8fb5002c 	lw	s5,44(r29)
 b80:	8fb40028 	lw	s4,40(r29)
 b84:	8fb30024 	lw	s3,36(r29)
 b88:	8fb20020 	lw	s2,32(r29)
 b8c:	8fb1001c 	lw	s1,28(r29)
 b90:	02041023 	subu	r2,s0,r4
 b94:	8fb00018 	lw	s0,24(r29)
 b98:	03e00008 	jr	r31
 b9c:	27bd0040 	addiu	r29,r29,64

00000ba0 <vsprintf>:
 ba0:	27bdffe8 	addiu	r29,r29,-24
 ba4:	00a01021 	move	r2,r5
 ba8:	00c03821 	move	r7,r6
 bac:	2405ffff 	li	r5,-1
 bb0:	afbf0010 	sw	r31,16(r29)
 bb4:	0c00018a 	jal	628 <_vsnprintf>
 bb8:	00403021 	move	r6,r2
 bbc:	8fbf0010 	lw	r31,16(r29)
 bc0:	00000000 	nop
 bc4:	03e00008 	jr	r31
 bc8:	27bd0018 	addiu	r29,r29,24

00000bcc <sprintf>:
 bcc:	afa50004 	sw	r5,4(r29)
 bd0:	afa60008 	sw	r6,8(r29)
 bd4:	afa7000c 	sw	r7,12(r29)
 bd8:	27bdffe8 	addiu	r29,r29,-24
 bdc:	afbf0010 	sw	r31,16(r29)
 be0:	0c0002e8 	jal	ba0 <vsprintf>
 be4:	27a60020 	addiu	r6,r29,32
 be8:	8fbf0010 	lw	r31,16(r29)
 bec:	00000000 	nop
 bf0:	03e00008 	jr	r31
 bf4:	27bd0018 	addiu	r29,r29,24

00000bf8 <monprintf>:
 bf8:	afa40000 	sw	r4,0(r29)
 bfc:	afa50004 	sw	r5,4(r29)
 c00:	afa60008 	sw	r6,8(r29)
 c04:	afa7000c 	sw	r7,12(r29)
 c08:	27bdfee8 	addiu	r29,r29,-280
 c0c:	00802821 	move	r5,r4
 c10:	27a40010 	addiu	r4,r29,16
 c14:	afbf0110 	sw	r31,272(r29)
 c18:	0c0002e8 	jal	ba0 <vsprintf>
 c1c:	27a6011c 	addiu	r6,r29,284
 c20:	10400003 	beqz	r2,c30 <monprintf+0x38>
 c24:	00000000 	nop
 c28:	0c000056 	jal	158 <PutString>
 c2c:	27a40010 	addiu	r4,r29,16
 c30:	8fbf0110 	lw	r31,272(r29)
 c34:	00000000 	nop
 c38:	03e00008 	jr	r31
 c3c:	27bd0118 	addiu	r29,r29,280

00000c40 <tolower>:
 c40:	308400ff 	andi	r4,r4,0xff
 c44:	3c020000 	lui	r2,0x0
 c48:	00441021 	addu	r2,r2,r4
 c4c:	90420f70 	lbu	r2,3952(r2)
 c50:	00000000 	nop
 c54:	30420001 	andi	r2,r2,0x1
 c58:	10400002 	beqz	r2,c64 <tolower+0x24>
 c5c:	24820020 	addiu	r2,r4,32
 c60:	304400ff 	andi	r4,r2,0xff
 c64:	03e00008 	jr	r31
 c68:	00801021 	move	r2,r4

00000c6c <toupper>:
 c6c:	308400ff 	andi	r4,r4,0xff
 c70:	3c020000 	lui	r2,0x0
 c74:	00441021 	addu	r2,r2,r4
 c78:	90420f70 	lbu	r2,3952(r2)
 c7c:	00000000 	nop
 c80:	30420002 	andi	r2,r2,0x2
 c84:	10400002 	beqz	r2,c90 <toupper+0x24>
 c88:	2482ffe0 	addiu	r2,r4,-32
 c8c:	304400ff 	andi	r4,r2,0xff
 c90:	03e00008 	jr	r31
 c94:	00801021 	move	r2,r4
	...

00000ca0 <print>:
 ca0:	27bdffe0 	addiu	r29,r29,-32
 ca4:	afb10014 	sw	s1,20(r29)
 ca8:	00008821 	move	s1,r0
 cac:	afb20018 	sw	s2,24(r29)
 cb0:	00a09021 	move	s2,r5
 cb4:	00042600 	sll	r4,r4,0x18
 cb8:	00042603 	sra	r4,r4,0x18
 cbc:	afbf001c 	sw	r31,28(r29)
 cc0:	1a40000a 	blez	s2,cec <print+0x4c>
 cc4:	afb00010 	sw	s0,16(r29)
 cc8:	00048600 	sll	s0,r4,0x18
 ccc:	0c000052 	jal	148 <PutChar>
 cd0:	00102603 	sra	r4,s0,0x18
 cd4:	3c010100 	lui	r1,0x100
 cd8:	00308021 	addu	s0,r1,s0
 cdc:	26310001 	addiu	s1,s1,1
 ce0:	0232102a 	slt	r2,s1,s2
 ce4:	1440fff9 	bnez	r2,ccc <print+0x2c>
 ce8:	00000000 	nop
 cec:	0c000052 	jal	148 <PutChar>
 cf0:	2404000a 	li	r4,10
 cf4:	8fbf001c 	lw	r31,28(r29)
 cf8:	8fb20018 	lw	s2,24(r29)
 cfc:	8fb10014 	lw	s1,20(r29)
 d00:	8fb00010 	lw	s0,16(r29)
 d04:	03e00008 	jr	r31
 d08:	27bd0020 	addiu	r29,r29,32

00000d0c <main>:
 d0c:	27bdffe8 	addiu	r29,r29,-24
 d10:	afbf0010 	sw	r31,16(r29)
 d14:	0c00006a 	jal	1a8 <__main>
 d18:	00000000 	nop
 d1c:	24040061 	li	r4,97
 d20:	0c000328 	jal	ca0 <print>
 d24:	24050004 	li	r5,4
 d28:	8fbf0010 	lw	r31,16(r29)
 d2c:	24020006 	li	r2,6
 d30:	03e00008 	jr	r31
 d34:	27bd0018 	addiu	r29,r29,24
	...
