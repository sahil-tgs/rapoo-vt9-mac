
void FUN_01029920(void)

{
  undefined4 *puVar1;
  undefined1 auStack_a4 [32];
  undefined4 uStack_84;
  int iStack_80;
  undefined1 auStack_7c [24];
  undefined4 uStack_64;
  undefined1 *puStack_60;
  undefined1 **ppuStack_5c;
  int *piStack_58;
  uint uStack_54;
  undefined1 local_4c [8];
  undefined1 local_44 [8];
  undefined1 local_3c [8];
  undefined1 *local_34;
  undefined4 local_30;
  undefined1 *local_28;
  undefined1 *local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_012175a2;
  local_10 = ExceptionList;
  uStack_54 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piStack_58 = (int *)0x102994e;
  FUN_00fcf2c0();
  piStack_58 = (int *)0x1029955;
  local_18 = FUN_01163160();
  if (local_18 != 0) {
    local_1c = &LAB_00fec1a0;
    piStack_58 = &local_18;
    ppuStack_5c = &local_1c;
    puStack_60 = local_3c;
    uStack_64 = 0x102997a;
    piStack_58 = (int *)make_pair<>();
    ppuStack_5c = (undefined1 **)0x102998c;
    FUN_00feae60();
    local_20 = &LAB_0101c10a;
    piStack_58 = &local_18;
    ppuStack_5c = &local_20;
    puStack_60 = local_44;
    uStack_64 = 0x10299a4;
    piStack_58 = (int *)make_pair<>();
    ppuStack_5c = (undefined1 **)0x10299b6;
    FUN_01001e10();
    local_24 = &LAB_01031d05;
    piStack_58 = &local_18;
    ppuStack_5c = &local_24;
    puStack_60 = local_4c;
    uStack_64 = 0x10299ce;
    piStack_58 = (int *)make_pair<>();
    ppuStack_5c = (undefined1 **)0x10299e0;
    FUN_010313f0();
    local_28 = auStack_7c;
    iStack_80 = local_14;
    uStack_84 = 0x10299f4;
    puVar1 = (undefined4 *)FUN_00fb8360();
    iStack_80 = *puVar1;
    uStack_84 = 0x10299fe;
    local_30 = FID_conflict_function<void___cdecl(Concurrency::message<unsigned_int>*)><<lambda_585d1183dd7288406f8b545e733d6ea7>,void>
                         ();
    local_8 = 0;
    local_34 = auStack_a4;
    function<>(local_14 + 0x280);
    local_8 = 0xffffffff;
    FUN_00fd8d10();
  }
  ExceptionList = local_10;
  return;
}


=====
