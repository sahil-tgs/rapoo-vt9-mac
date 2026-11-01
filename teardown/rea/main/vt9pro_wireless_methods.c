
/* ===== 0x112c980 ===== */

undefined4 FUN_0112c980(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_010d7bd0();
  if ((param_1 & 1) != 0) {
    FUN_01209c9b(in_ECX,0x678);
  }
  return in_ECX;
}


/* ===== 0x1174fb0 ===== */

void FUN_01174fb0(void)

{
  char cVar1;
  undefined4 uVar2;
  QMessageLogger *pQVar3;
  QDebug *pQVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined1 auStack_110 [28];
  undefined4 uStack_f4;
  QEventLoop *pQStack_f0;
  int iStack_ec;
  undefined1 auStack_e8 [16];
  undefined4 uStack_d8;
  undefined1 uVar6;
  char *pcVar7;
  QMessageLogger local_b4 [20];
  QMessageLogger local_a0 [28];
  undefined1 *local_84;
  undefined1 *local_80;
  undefined4 local_7c;
  undefined1 *local_78;
  undefined1 *local_74;
  QEventLoop local_70 [8];
  undefined1 *local_68;
  int local_64;
  QDebug local_60 [4];
  QDebug *local_5c;
  QDebug *local_58;
  QDebug local_54 [4];
  QDebug *local_50;
  QDebug *local_4c;
  int local_48;
  undefined1 local_42;
  undefined1 local_41;
  int local_40;
  undefined1 local_3c [40];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01236d64;
  local_10 = ExceptionList;
  local_14 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_40 = in_ECX;
  if (*(int *)(in_ECX + 0x1a8) != 0) {
    QObject::deleteLater(*(QObject **)(in_ECX + 0x1a8));
    *(undefined4 *)(local_40 + 0x1a8) = 0;
  }
  FUN_010f41d0();
  uVar2 = FUN_00fbfd40();
  *(undefined4 *)(local_40 + 0x1a8) = uVar2;
  FUN_010f41d0();
  uVar2 = FUN_00fbfda0();
  *(undefined4 *)(local_40 + 0x628) = uVar2;
  local_48 = 0;
  while (((cVar1 = FUN_00fc5fe0(), cVar1 == '\0' && (local_48 < 3)) &&
         (*(char *)(local_40 + 9) == '\0'))) {
    Sleep(500);
    pcVar7 = "[ERROR] init fail retry";
    pQVar4 = local_54;
    uStack_d8 = 0x11750b4;
    pQVar3 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_a0,(char *)0x0,0,(char *)0x0);
    local_50 = (QDebug *)QMessageLogger::debug(pQVar3);
    local_8 = 0;
    local_4c = local_50;
    pQVar4 = QDebug::operator<<(local_50,(char *)pQVar4);
    QDebug::operator<<(pQVar4,(int)pcVar7);
    local_8 = 0xffffffff;
    QDebug::~QDebug(local_54);
    local_48 = local_48 + 1;
  }
  if (*(char *)(local_40 + 9) == '\0') {
    local_41 = local_48 < 3;
    *(undefined1 *)(local_40 + 8) = local_41;
    uVar6 = 8;
    pQVar4 = local_60;
    uStack_d8 = 0x1175140;
    pQVar3 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_b4,(char *)0x0,0,(char *)0x0);
    local_5c = (QDebug *)QMessageLogger::debug(pQVar3);
    local_8 = 1;
    local_58 = local_5c;
    pQVar4 = QDebug::operator<<(local_5c,(char *)pQVar4);
    QDebug::operator<<(pQVar4,(bool)uVar6);
    local_8 = 0xffffffff;
    QDebug::~QDebug(local_60);
    QEventLoop::QEventLoop(local_70,(QObject *)0x0);
    local_8 = 2;
    if (*(char *)(local_40 + 8) != '\0') {
      local_64 = local_40;
      local_68 = &LAB_010f3b7c;
      local_74 = &stack0xffffff38;
      uStack_d8 = 0x11751bd;
      make_pair<>();
      FID_conflict_function<void___cdecl(Concurrency::message<unsigned_int>*)><<lambda_585d1183dd7288406f8b545e733d6ea7>,void>
                ();
      local_8._0_1_ = 3;
      local_78 = auStack_e8;
      iStack_ec = local_40;
      pQStack_f0 = local_70;
      uStack_f4 = 0x11751e7;
      puVar5 = (undefined4 *)FUN_00fc13f0();
      iStack_ec = puVar5[1];
      pQStack_f0 = (QEventLoop *)*puVar5;
      uStack_f4 = 0x11751f5;
      local_7c = FID_conflict_function<void___cdecl(Concurrency::message<unsigned_int>*)><<lambda_585d1183dd7288406f8b545e733d6ea7>,void>
                           ();
      local_8._0_1_ = 4;
      local_80 = auStack_110;
      function<>(local_3c);
      local_8._0_1_ = 3;
      FUN_00fd8c20();
      local_84 = &stack0xffffff3c;
      FUN_00fb8360();
      QEventLoop::exec(local_70);
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_00fb87f0();
    }
    local_42 = *(undefined1 *)(local_40 + 8);
    local_8 = 0xffffffff;
    QEventLoop::~QEventLoop(local_70);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1175280 ===== */

int FUN_01175280(void)

{
  int in_ECX;
  
  return in_ECX + 0x1ac;
}


/* ===== 0x11752a0 ===== */

void FUN_011752a0(void)

{
  uint uVar1;
  bool *pbVar2;
  int iVar3;
  QString local_64 [4];
  QString *local_60;
  QString *local_5c;
  QString local_58 [4];
  QString *local_54;
  QString *local_50;
  undefined4 local_4c;
  int *local_48;
  void *local_44;
  char local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01236d9e;
  local_10 = ExceptionList;
  uVar1 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  local_44 = malloc(0x20);
  if (local_44 != (void *)0x0) {
    memset(local_44,0,0x20);
    local_3d = 0;
    local_3e = 0xa3;
    FUN_011825d0(local_44,&local_3e,&local_3d,0);
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_3f = 0xba;
    local_4c = 0x20;
    local_40 = (**(code **)(*local_48 + 0x150))(local_44,&local_38,&local_4c,&local_3f,uVar1);
    free(local_44);
    if (local_40 != '\0') {
      local_3c = 0;
      if (local_38._2_1_ == 0) {
        local_3c = local_38 >> 8 & 0xff;
      }
      else {
        iVar3 = 10;
        pbVar2 = (bool *)0x0;
        local_54 = (QString *)QString::number((int)local_58,(uint)local_38._2_1_);
        local_8 = 0;
        local_50 = local_54;
        iVar3 = QString::toInt(local_54,pbVar2,iVar3);
        local_3c = iVar3 * 100;
        local_8 = 0xffffffff;
        QString::~QString(local_58);
        iVar3 = 10;
        pbVar2 = (bool *)0x0;
        local_60 = (QString *)QString::number((int)local_64,local_38 >> 8 & 0xff);
        local_8 = 1;
        local_5c = local_60;
        iVar3 = QString::toInt(local_60,pbVar2,iVar3);
        local_3c = iVar3 + local_3c;
        local_8 = 0xffffffff;
        QString::~QString(local_64);
      }
      local_48[0x78] = local_3c;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1175490 ===== */

void FUN_01175490(void)

{
  undefined4 local_40;
  uint local_3c;
  void *local_38;
  int *local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  char local_2d;
  undefined4 local_2c;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  local_38 = malloc(0x20);
  if (local_38 != (void *)0x0) {
    memset(local_38,0,0x20);
    local_2e = 0x18;
    local_2f = 0xa4;
    FUN_011825d0(local_38,&local_2f,&local_2e,0x898);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_30 = 0xba;
    local_40 = 0x20;
    local_2d = (**(code **)(*local_34 + 0x150))(local_38,&local_2c,&local_40,&local_30);
    free(local_38);
    if (local_2d == '\0') {
      local_3c = 0xffffffff;
    }
    else {
      *(undefined1 *)((int)local_34 + 0x49b) = (undefined1)local_28;
      local_34[0x7c] = local_28 & 0xff;
      local_3c = (uint)*(byte *)((int)local_34 + 0x49b);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x11755b0 ===== */

/* WARNING: Type propagation algorithm not settling */

void FUN_011755b0(void)

{
  uint uVar1;
  int local_5c [3];
  undefined1 local_50 [4];
  void *local_4c;
  int local_48;
  char local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  short local_40;
  int *local_3c;
  byte local_38 [36];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01236dcb;
  local_10 = ExceptionList;
  uVar1 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_5c[2] = 0;
  local_14 = uVar1;
  local_4c = malloc(0x20);
  memset(local_4c,0,0x20);
  local_41 = 0x18;
  local_42 = 0xa4;
  FUN_011825d0(local_4c,&local_42,&local_41,0x888);
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  local_38[7] = 0;
  local_38[8] = 0;
  local_38[9] = 0;
  local_38[10] = 0;
  local_38[0xb] = 0;
  local_38[0xc] = 0;
  local_38[0xd] = 0;
  local_38[0xe] = 0;
  local_38[0xf] = 0;
  local_38[0x10] = 0;
  local_38[0x11] = 0;
  local_38[0x12] = 0;
  local_38[0x13] = 0;
  local_38[0x14] = 0;
  local_38[0x15] = 0;
  local_38[0x16] = 0;
  local_38[0x17] = 0;
  local_38[0x18] = 0;
  local_38[0x19] = 0;
  local_38[0x1a] = 0;
  local_38[0x1b] = 0;
  local_38[0x1c] = 0;
  local_38[0x1d] = 0;
  local_38[0x1e] = 0;
  local_38[0x1f] = 0;
  local_38[0x20] = 0;
  local_43 = 0xba;
  local_5c[1] = 0x20;
  local_44 = (**(code **)(*local_3c + 0x150))(local_4c,local_38,local_5c + 1,&local_43,uVar1);
  free(local_4c);
  FUN_00fb8560();
  local_8 = 0;
  if (local_44 != '\0') {
    *(byte *)((int)local_3c + 0x48b) = local_38[4];
    *(byte *)(local_3c + 0x123) = local_38[5];
    *(byte *)((int)local_3c + 0x48d) = local_38[6];
    *(byte *)((int)local_3c + 0x48e) = local_38[7];
    *(byte *)((int)local_3c + 0x48f) = local_38[8];
    *(byte *)(local_3c + 0x124) = local_38[9];
    *(byte *)((int)local_3c + 0x491) = local_38[10];
    *(byte *)((int)local_3c + 0x493) = local_38[0xb];
    *(byte *)(local_3c + 0x125) = local_38[0xc];
    *(byte *)((int)local_3c + 0x495) = local_38[0xd];
    *(byte *)((int)local_3c + 0x496) = local_38[0xe];
    *(byte *)((int)local_3c + 0x497) = local_38[0xf];
    *(byte *)(local_3c + 0x126) = local_38[0x10];
    local_40 = 0;
    for (local_48 = 2; local_48 < 9; local_48 = local_48 + 1) {
      local_40 = (ushort)local_38[local_48 * 2 + 1] << 8;
      local_5c[0] = ((uint)local_38[local_48 * 2 + 1] * 0x100 + (uint)local_38[local_48 * 2]) * 0x32
      ;
      FUN_00ff6c50(local_5c);
    }
  }
  FUN_00ff62d0(local_50);
  local_5c[2] = local_5c[2] | 1;
  local_8 = 0xffffffff;
  FUN_00fb86c0();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1175850 ===== */

void FUN_01175850(void)

{
  undefined4 local_40;
  uint local_3c;
  int *local_38;
  void *local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  char local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  local_34 = malloc(0x20);
  if (local_34 != (void *)0x0) {
    memset(local_34,0,0x20);
    local_2e = 0x18;
    local_2f = 0xa4;
    FUN_011825d0(local_34,&local_2f,&local_2e,0x896);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_30 = 0xba;
    local_40 = 0x20;
    local_2d = (**(code **)(*local_38 + 0x150))(local_34,&local_2c,&local_40,&local_30);
    free(local_34);
    if (local_2d == '\0') {
      local_3c = 0xffffffff;
    }
    else {
      *(char *)((int)local_38 + 0x499) = (char)local_28 + '\x01';
      local_3c = (uint)*(byte *)((int)local_38 + 0x499);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1175960 ===== */

void FUN_01175960(void)

{
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  void *local_40;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  int *local_38;
  byte local_32;
  char local_31;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  local_40 = malloc(0x20);
  if (local_40 != (void *)0x0) {
    memset(local_40,0,0x20);
    local_39 = 0x18;
    local_3a = 0xa4;
    FUN_011825d0(local_40,&local_3a,&local_39,0x880);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_3b = 0xba;
    local_50 = 0x20;
    local_31 = (**(code **)(*local_38 + 0x150))(local_40,&local_2c,&local_50,&local_3b);
    free(local_40);
    if (local_31 != '\0') {
      *(byte *)((int)local_38 + 0x483) = (byte)local_28;
      *(byte *)(local_38 + 0x121) = local_28._1_1_;
      *(byte *)((int)local_38 + 0x485) = local_28._2_1_;
    }
    local_30 = 0;
    if (local_31 != '\0') {
      if ((char)local_38[0x77] == '\0') {
        if ((local_38[0x78] < local_38[0x7a]) || ((char)local_38[0x6f] != -1)) {
          local_32 = (byte)local_28;
        }
        else {
          local_32 = local_28._2_1_;
        }
        local_48 = local_32 - 1;
        switch(local_32) {
        case 1:
          local_30 = 3;
          break;
        case 2:
          local_30 = 2;
          break;
        case 4:
          local_30 = 1;
          break;
        case 8:
          local_30 = 0;
          break;
        case 0x81:
          local_30 = 6;
          break;
        case 0x82:
          local_30 = 5;
          break;
        case 0x84:
          local_30 = 4;
          break;
        case 0x88:
          local_30 = 3;
        }
      }
      else {
        local_44 = local_28._1_1_ - 1;
        switch(local_28._1_1_) {
        case 1:
          local_30 = 0;
          break;
        case 2:
          local_30 = 6;
          break;
        case 4:
          local_30 = 5;
          break;
        case 8:
          local_30 = 4;
          break;
        case 0x81:
          local_30 = 3;
          break;
        case 0x82:
          local_30 = 2;
          break;
        case 0x84:
          local_30 = 1;
          break;
        case 0x88:
          local_30 = 0;
        }
      }
    }
    if (local_31 == '\0') {
      local_4c = 0xffffffff;
    }
    else {
      local_4c = local_30;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1175d40 ===== */

void FUN_01175d40(void)

{
  undefined4 local_40;
  uint local_3c;
  int *local_38;
  void *local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  char local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  local_34 = malloc(0x20);
  if (local_34 != (void *)0x0) {
    memset(local_34,0,0x20);
    local_2e = 0x18;
    local_2f = 0xa4;
    FUN_011825d0(local_34,&local_2f,&local_2e,0x898);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_30 = 0xba;
    local_40 = 0x20;
    local_2d = (**(code **)(*local_38 + 0x150))(local_34,&local_2c,&local_40,&local_30);
    free(local_34);
    if (local_2d == '\0') {
      local_3c = 0xffffffff;
    }
    else {
      *(undefined1 *)(local_38 + 0x127) = local_28._1_1_;
      local_3c = (uint)*(byte *)(local_38 + 0x127);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1175e50 ===== */

/* WARNING: Exceeded maximum restarts with more pending */

void FUN_01175e50(void)

{
  undefined4 local_48;
  uint local_44;
  uint local_40;
  void *local_3c;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  int *local_34;
  char local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  local_3c = malloc(0x20);
  if (local_3c != (void *)0x0) {
    memset(local_3c,0,0x20);
    local_35 = 0x18;
    local_36 = 0xa4;
    FUN_011825d0(local_3c,&local_36,&local_35,0x898);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_37 = 0xba;
    local_48 = 0x20;
    local_2d = (**(code **)(*local_34 + 0x150))(local_3c,&local_2c,&local_48,&local_37);
    free(local_3c);
    if (local_2d != '\0') {
      *(byte *)((int)local_34 + 0x49d) = local_28._2_1_;
    }
    local_40 = (uint)local_28._2_1_;
    switch(local_40) {
    case 0x1175f75:
                    /* WARNING: This code block may not be properly labeled as switch case */
      *(undefined1 *)((int)local_34 + 0x49d) = 10;
    }
    if (local_2d == '\0') {
      local_44 = 0xffffffff;
    }
    else {
      local_44 = (uint)*(byte *)((int)local_34 + 0x49d);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1175fd0 ===== */

void FUN_01175fd0(void)

{
  undefined4 local_40;
  uint local_3c;
  int *local_38;
  void *local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  char local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  local_34 = malloc(0x20);
  if (local_34 != (void *)0x0) {
    memset(local_34,0,0x20);
    local_2e = 0x18;
    local_2f = 0xa4;
    FUN_011825d0(local_34,&local_2f,&local_2e,0x898);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_30 = 0xba;
    local_40 = 0x20;
    local_2d = (**(code **)(*local_38 + 0x150))(local_34,&local_2c,&local_40,&local_30);
    free(local_34);
    if (local_2d == '\0') {
      local_3c = 0xffffffff;
    }
    else {
      *(char *)((int)local_38 + 0x49e) = local_28._3_1_ + '\x01';
      local_3c = (uint)*(byte *)((int)local_38 + 0x49e);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x11760e0 ===== */

void FUN_011760e0(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined4 local_8c;
  uint local_88;
  QString local_84 [4];
  QString local_80 [4];
  QString local_7c [4];
  QString local_78 [4];
  QString local_74 [4];
  QString local_70 [4];
  QString local_6c [4];
  QString local_68 [4];
  QString local_64 [4];
  QString local_60 [4];
  QString local_5c [4];
  QString local_58 [4];
  int local_54;
  int local_50;
  undefined4 local_4c;
  void *local_48;
  char local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40 [4];
  int *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01236e64;
  local_10 = ExceptionList;
  uVar1 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_88 = 0;
  local_14 = uVar1;
  local_48 = malloc(0x20);
  memset(local_48,0,0x20);
  local_54 = param_2;
  if (param_2 == 0) {
    local_4c = 0x8b8;
  }
  else if (param_2 == 1) {
    local_4c = 0x8b9;
  }
  else {
    local_4c = 0x8b8;
  }
  local_41 = 0x18;
  local_42 = 0xa4;
  FUN_011825d0(local_48,&local_42,&local_41,local_4c);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_43 = 0xba;
  local_8c = 0x20;
  local_44 = (**(code **)(*local_3c + 0x150))(local_48,&local_38,&local_8c,&local_43,uVar1);
  free(local_48);
  FUN_00fc1060();
  local_8 = 0;
  if (local_44 != '\0') {
    local_50 = param_2;
    if (param_2 == 0) {
      *(undefined1 *)((int)local_3c + 0x4bd) = local_34._2_1_;
      *(undefined1 *)(local_3c + 0x12f) = local_34._1_1_;
      *(undefined1 *)((int)local_3c + 0x4bb) = (undefined1)local_34;
      QString::QString(local_58,"r");
      local_8._0_1_ = 1;
      uVar1 = local_34 & 0xff;
      puVar2 = (uint *)FUN_010cf220(local_58);
      *puVar2 = uVar1;
      local_8._0_1_ = 0;
      QString::~QString(local_58);
      QString::QString(local_5c,"g");
      local_8._0_1_ = 2;
      uVar1 = local_34 >> 8;
      puVar2 = (uint *)FUN_010cf220(local_5c);
      *puVar2 = uVar1 & 0xff;
      local_8._0_1_ = 0;
      QString::~QString(local_5c);
      QString::QString(local_60,"b");
      local_8._0_1_ = 3;
      uVar1 = local_34 >> 0x10;
      puVar2 = (uint *)FUN_010cf220(local_60);
      *puVar2 = uVar1 & 0xff;
      local_8 = (uint)local_8._1_3_ << 8;
      QString::~QString(local_60);
    }
    else if (param_2 == 1) {
      *(undefined1 *)((int)local_3c + 0x4c1) = local_34._2_1_;
      *(undefined1 *)(local_3c + 0x130) = local_34._1_1_;
      *(undefined1 *)((int)local_3c + 0x4bf) = (undefined1)local_34;
      QString::QString(local_64,"r");
      local_8._0_1_ = 4;
      uVar1 = local_34 & 0xff;
      puVar2 = (uint *)FUN_010cf220(local_64);
      *puVar2 = uVar1;
      local_8._0_1_ = 0;
      QString::~QString(local_64);
      QString::QString(local_68,"g");
      local_8._0_1_ = 5;
      uVar1 = local_34 >> 8;
      puVar2 = (uint *)FUN_010cf220(local_68);
      *puVar2 = uVar1 & 0xff;
      local_8._0_1_ = 0;
      QString::~QString(local_68);
      QString::QString(local_6c,"b");
      local_8._0_1_ = 6;
      uVar1 = local_34 >> 0x10;
      puVar2 = (uint *)FUN_010cf220(local_6c);
      *puVar2 = uVar1 & 0xff;
      local_8 = (uint)local_8._1_3_ << 8;
      QString::~QString(local_6c);
    }
    else if (param_2 == 2) {
      *(undefined1 *)((int)local_3c + 0x4c5) = local_34._2_1_;
      *(undefined1 *)(local_3c + 0x131) = local_34._1_1_;
      *(undefined1 *)((int)local_3c + 0x4c3) = (undefined1)local_34;
      QString::QString(local_70,"r");
      local_8._0_1_ = 7;
      uVar1 = local_34 & 0xff;
      puVar2 = (uint *)FUN_010cf220(local_70);
      *puVar2 = uVar1;
      local_8._0_1_ = 0;
      QString::~QString(local_70);
      QString::QString(local_74,"g");
      local_8._0_1_ = 8;
      uVar1 = local_34 >> 8;
      puVar2 = (uint *)FUN_010cf220(local_74);
      *puVar2 = uVar1 & 0xff;
      local_8._0_1_ = 0;
      QString::~QString(local_74);
      QString::QString(local_78,"b");
      local_8._0_1_ = 9;
      uVar1 = local_34 >> 0x10;
      puVar2 = (uint *)FUN_010cf220(local_78);
      *puVar2 = uVar1 & 0xff;
      local_8 = (uint)local_8._1_3_ << 8;
      QString::~QString(local_78);
    }
    else {
      *(undefined1 *)((int)local_3c + 0x4bd) = local_34._2_1_;
      *(undefined1 *)(local_3c + 0x12f) = local_34._1_1_;
      *(undefined1 *)((int)local_3c + 0x4bb) = (undefined1)local_34;
      QString::QString(local_7c,"r");
      local_8._0_1_ = 10;
      uVar1 = local_34 & 0xff;
      puVar2 = (uint *)FUN_010cf220(local_7c);
      *puVar2 = uVar1;
      local_8._0_1_ = 0;
      QString::~QString(local_7c);
      QString::QString(local_80,"g");
      local_8._0_1_ = 0xb;
      uVar1 = local_34 >> 8;
      puVar2 = (uint *)FUN_010cf220(local_80);
      *puVar2 = uVar1 & 0xff;
      local_8._0_1_ = 0;
      QString::~QString(local_80);
      QString::QString(local_84,"b");
      local_8._0_1_ = 0xc;
      uVar1 = local_34 >> 0x10;
      puVar2 = (uint *)FUN_010cf220(local_84);
      *puVar2 = uVar1 & 0xff;
      local_8 = (uint)local_8._1_3_ << 8;
      QString::~QString(local_84);
    }
  }
  FUN_00fef880(local_40);
  local_88 = local_88 | 1;
  local_8 = 0xffffffff;
  FUN_00fe1210();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1129d80 ===== */

void FUN_01129d80(void)

{
  char cVar1;
  QMessageLogger *pQVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  QDebug *pQVar7;
  undefined1 *puVar8;
  QMessageLogger local_1c8 [20];
  QMessageLogger local_1b4 [20];
  QMessageLogger local_1a0 [20];
  undefined1 local_18c [44];
  undefined1 local_160 [4];
  undefined1 local_15c [4];
  QDebug *local_158;
  QDebug *local_154;
  undefined4 local_150;
  int local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined1 local_110 [4];
  QDebug local_10c [4];
  QDebug *local_108;
  QDebug *local_104;
  undefined4 local_100;
  QDebug local_fc [4];
  QDebug *local_f8;
  QDebug *local_f4;
  undefined4 local_f0;
  QDebug local_ec [8];
  undefined1 *local_e4;
  int local_e0;
  undefined1 local_d9;
  undefined1 local_d8;
  undefined1 local_d7;
  undefined1 local_d6;
  undefined1 local_d5;
  undefined1 local_d4;
  undefined1 local_d3;
  undefined1 local_d2;
  undefined1 local_d1;
  uint local_d0;
  int local_cc;
  undefined1 local_c8 [4];
  void *local_c4;
  byte local_bd;
  int *local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_7c [4];
  undefined1 local_78 [24];
  undefined1 local_60 [24];
  undefined1 local_48 [16];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_012317c7;
  local_10 = ExceptionList;
  local_14 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_d0 = 0;
  FUN_00fc1060(local_14);
  local_8 = 0;
  local_c4 = malloc(0x20);
  memset(local_c4,0,0x20);
  local_d1 = 0x18;
  local_d2 = 0xa4;
  FUN_011825d0(local_c4,&local_d2,&local_d1,0x600);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  memset(local_78,0,0x40);
  local_d3 = 0xba;
  local_13c = 0x20;
  cVar1 = (**(code **)(*local_b8 + 0x150))(local_c4,&local_38,&local_13c,&local_d3);
  if (cVar1 == '\0') {
    pQVar7 = local_ec;
    pQVar2 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_1a0,(char *)0x0,0,(char *)0x0);
    local_158 = (QDebug *)QMessageLogger::debug(pQVar2);
    local_8._0_1_ = 1;
    local_154 = local_158;
    QDebug::operator<<(local_158,(char *)pQVar7);
    local_8 = (uint)local_8._1_3_ << 8;
    QDebug::~QDebug(local_ec);
    free(local_c4);
    FUN_00fef880(local_c8);
    local_d0 = local_d0 | 1;
    local_8 = 0xffffffff;
    FUN_00fe1260();
  }
  else {
    memcpy(local_78,&local_34,0x18);
    memset(local_c4,0,0x20);
    local_d4 = 0x18;
    local_d5 = 0xa4;
    FUN_011825d0(local_c4,&local_d5,&local_d4,0x618);
    memset(&local_38,0,0x21);
    local_d6 = 0xba;
    local_f0 = 0x20;
    cVar1 = (**(code **)(*local_b8 + 0x150))(local_c4,&local_38,&local_f0,&local_d6);
    if (cVar1 == '\0') {
      pQVar7 = local_fc;
      pQVar2 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_1b4,(char *)0x0,0,(char *)0x0)
      ;
      local_f8 = (QDebug *)QMessageLogger::debug(pQVar2);
      local_8._0_1_ = 2;
      local_f4 = local_f8;
      QDebug::operator<<(local_f8,(char *)pQVar7);
      local_8 = (uint)local_8._1_3_ << 8;
      QDebug::~QDebug(local_fc);
      free(local_c4);
      FUN_00fef880(local_c8);
      local_d0 = local_d0 | 1;
      local_8 = 0xffffffff;
      FUN_00fe1260();
    }
    else {
      memcpy(local_60,&local_34,0x18);
      memset(local_c4,0,0x20);
      local_d9 = 0x18;
      local_d7 = 0xa4;
      FUN_011825d0(local_c4,&local_d7,&local_d9,0x630);
      memset(&local_38,0,0x21);
      local_d8 = 0xba;
      local_100 = 0x20;
      cVar1 = (**(code **)(*local_b8 + 0x150))(local_c4,&local_38,&local_100,&local_d8);
      if (cVar1 == '\0') {
        pQVar7 = local_10c;
        pQVar2 = (QMessageLogger *)
                 QMessageLogger::QMessageLogger(local_1c8,(char *)0x0,0,(char *)0x0);
        local_108 = (QDebug *)QMessageLogger::debug(pQVar2);
        local_8._0_1_ = 3;
        local_104 = local_108;
        QDebug::operator<<(local_108,(char *)pQVar7);
        local_8 = (uint)local_8._1_3_ << 8;
        QDebug::~QDebug(local_10c);
        free(local_c4);
        FUN_00fef880(local_c8);
        local_d0 = local_d0 | 1;
        local_8 = 0xffffffff;
        FUN_00fe1260();
      }
      else {
        free(local_c4);
        memcpy(local_48,&local_34,8);
        FUN_00fc1060();
        local_8._0_1_ = 4;
        for (local_cc = 0; local_cc < 0xe; local_cc = local_cc + 1) {
          FUN_010e3880(local_78[local_cc * 4],local_78[local_cc * 4 + 2],local_78[local_cc * 4 + 1],
                       local_78[local_cc * 4 + 3]);
          FUN_010f40d0(local_160,&local_cc,local_110);
        }
        local_114 = 0;
        piVar3 = (int *)FUN_01104090(&local_114);
        local_b8[0x7d] = *piVar3;
        local_118 = 1;
        piVar3 = (int *)FUN_01104090(&local_118);
        local_b8[0x7e] = *piVar3;
        local_11c = 2;
        piVar3 = (int *)FUN_01104090(&local_11c);
        local_b8[0x7f] = *piVar3;
        local_120 = 3;
        piVar3 = (int *)FUN_01104090(&local_120);
        local_b8[0x80] = *piVar3;
        local_124 = 4;
        piVar3 = (int *)FUN_01104090(&local_124);
        local_b8[0x81] = *piVar3;
        local_128 = 5;
        piVar3 = (int *)FUN_01104090(&local_128);
        local_b8[0x82] = *piVar3;
        local_12c = 6;
        piVar3 = (int *)FUN_01104090(&local_12c);
        local_b8[0x83] = *piVar3;
        local_130 = 7;
        piVar3 = (int *)FUN_01104090(&local_130);
        local_b8[0x84] = *piVar3;
        local_134 = 8;
        piVar3 = (int *)FUN_01104090(&local_134);
        local_b8[0x85] = *piVar3;
        local_138 = 9;
        piVar3 = (int *)FUN_01104090(&local_138);
        local_b8[0x86] = *piVar3;
        local_150 = 10;
        piVar3 = (int *)FUN_01104090(&local_150);
        local_b8[0x87] = *piVar3;
        local_140 = 0xb;
        piVar3 = (int *)FUN_01104090(&local_140);
        local_b8[0x88] = *piVar3;
        local_144 = 0xc;
        piVar3 = (int *)FUN_01104090(&local_144);
        local_b8[0x89] = *piVar3;
        local_148 = 0xd;
        piVar3 = (int *)FUN_01104090(&local_148);
        local_b8[0x8a] = *piVar3;
        local_b4 = 0;
        local_b0 = 2;
        local_ac = 1;
        local_a8 = 5;
        local_a4 = 6;
        local_a0 = 7;
        local_9c = 8;
        local_98 = 9;
        local_94 = 10;
        local_90 = 0xb;
        local_8c = 0xc;
        local_88 = 0x8e;
        local_84 = 0x8f;
        local_80 = 0xd;
        puVar4 = (undefined4 *)FUN_00fc13f0(&local_b4,local_7c);
        FUN_00fc12b0(*puVar4,puVar4[1]);
        local_8._0_1_ = 5;
        local_e4 = local_78;
        local_14c = 0x600;
        local_bd = 0;
        local_e0 = 0;
        while( true ) {
          iVar5 = FUN_00fc0ae0();
          if (iVar5 <= local_e0) break;
          piVar3 = (int *)FUN_00fe8400(local_e0);
          if (*piVar3 == -1) {
            piVar3 = (int *)FUN_00fe8400(local_e0);
            if (*piVar3 != 4) goto LAB_0112a627;
            piVar3 = (int *)FUN_00fe8400(local_e0);
            if (*piVar3 != 3) goto LAB_0112a627;
          }
          else {
LAB_0112a627:
            FUN_01124b90(local_18c,local_e4,local_e4 + 1,local_e4 + 2,local_e4 + 3,
                         local_14c + (uint)local_bd * 4);
            local_8._0_1_ = 6;
            puVar8 = local_18c;
            uVar6 = FUN_00fe8400(local_e0);
            FUN_010dd600(local_15c,uVar6,puVar8);
            local_bd = local_bd + 1;
            local_e4 = local_e4 + 4;
            local_8._0_1_ = 5;
            FUN_01033240();
          }
          local_e0 = local_e0 + 1;
        }
        FUN_00fef880(local_c8);
        local_d0 = local_d0 | 1;
        local_8._0_1_ = 4;
        FUN_00fb86c0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00fc0220();
        local_8 = 0xffffffff;
        FUN_00fe1260();
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1176e20 ===== */

void FUN_01176e20(void)

{
  undefined4 local_40;
  uint local_3c;
  int *local_38;
  void *local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  char local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  local_34 = malloc(0x20);
  if (local_34 != (void *)0x0) {
    memset(local_34,0,0x20);
    local_2e = 4;
    local_2f = 0xa4;
    FUN_011825d0(local_34,&local_2f,&local_2e,0x884);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_30 = 0xba;
    local_40 = 0x20;
    local_2d = (**(code **)(*local_38 + 0x150))(local_34,&local_2c,&local_40,&local_30);
    free(local_34);
    if (local_2d == '\0') {
      local_3c = 0xffffffff;
    }
    else {
      *(char *)((int)local_38 + 0x487) = (char)local_28 + -1;
      local_3c = (uint)*(byte *)((int)local_38 + 0x487);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1177410 ===== */

/* WARNING: Exceeded maximum restarts with more pending */

void FUN_01177410(void)

{
  char cVar1;
  uint uVar2;
  QMessageLogger *this;
  QDebug *pQVar3;
  QMessageLogger local_74 [20];
  uint local_60;
  QDebug local_5c [4];
  QDebug *local_58;
  QDebug *local_54;
  undefined4 local_50;
  uint local_4c;
  int *local_48;
  void *local_44;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01236f44;
  local_10 = ExceptionList;
  uVar2 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_3c = 0;
  local_14 = uVar2;
  local_44 = malloc(0x20);
  if (local_44 != (void *)0x0) {
    memset(local_44,0,0x20);
    local_3d = 0x18;
    local_3e = 0xa4;
    FUN_011825d0(local_44,&local_3e,&local_3d,0x8ac);
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_3f = 0xba;
    local_50 = 0x20;
    cVar1 = (**(code **)(*local_48 + 0x150))(local_44,&local_38,&local_50,&local_3f,uVar2);
    if (cVar1 == '\0') {
      pQVar3 = local_5c;
      this = (QMessageLogger *)QMessageLogger::QMessageLogger(local_74,(char *)0x0,0,(char *)0x0);
      local_58 = (QDebug *)QMessageLogger::debug(this);
      local_8 = 0;
      local_54 = local_58;
      QDebug::operator<<(local_58,(char *)pQVar3);
      local_8 = 0xffffffff;
      QDebug::~QDebug(local_5c);
      free(local_44);
    }
    else {
      free(local_44);
      local_60 = local_34 >> 8 & 0xff;
      switch(local_60) {
      case 0x117756f:
                    /* WARNING: This code block may not be properly labeled as switch case */
        local_3c = 0;
        break;
      default:
        local_3c = 7;
      }
      local_4c = local_60;
      if (local_34._2_1_ == '\x01') {
        local_3c = 7;
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1176f40 ===== */

void FUN_01176f40(void)

{
  undefined4 local_40;
  uint local_3c;
  void *local_38;
  int *local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  char local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  local_38 = malloc(0x20);
  if (local_38 != (void *)0x0) {
    memset(local_38,0,0x20);
    local_2e = 4;
    local_2f = 0xa4;
    FUN_011825d0(local_38,&local_2f,&local_2e,0x89c);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_30 = 0xba;
    local_40 = 0x20;
    local_2d = (**(code **)(*local_34 + 0x150))(local_38,&local_2c,&local_40,&local_30);
    free(local_38);
    if (local_2d != '\0') {
      *(undefined1 *)((int)local_34 + 0x49f) = (undefined1)local_28;
      (**(code **)(*local_34 + 0x144))();
    }
    if (local_2d == '\0') {
      local_3c = 0xffffffff;
    }
    else {
      local_3c = (uint)*(byte *)((int)local_34 + 0x49f);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1177060 ===== */

void FUN_01177060(void)

{
  uint uVar1;
  QMessageLogger *pQVar2;
  QDebug *pQVar3;
  char *pcVar4;
  QMessageLogger local_a8 [20];
  QMessageLogger local_94 [20];
  QMessageLogger local_80 [20];
  QDebug local_6c [4];
  QDebug *local_68;
  QDebug *local_64;
  QDebug local_60 [4];
  QDebug *local_5c;
  QDebug *local_58;
  QDebug local_54 [4];
  QDebug *local_50;
  QDebug *local_4c;
  undefined4 local_48;
  void *local_44;
  int *local_40;
  char local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01236f13;
  local_10 = ExceptionList;
  uVar1 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  local_44 = malloc(0x20);
  if (local_44 != (void *)0x0) {
    memset(local_44,0,0x20);
    local_39 = 0;
    local_3a = 0xaa;
    FUN_011825d0(local_44,&local_3a,&local_39,0);
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_3b = 0xba;
    local_48 = 0x20;
    local_3c = (**(code **)(*local_40 + 0x150))(local_44,&local_38,&local_48,&local_3b,uVar1);
    free(local_44);
    if ((local_3c != '\0') && (local_38._1_1_ != '\0')) {
      if (local_38._1_1_ == '\x01') {
        pQVar3 = local_54;
        pQVar2 = (QMessageLogger *)
                 QMessageLogger::QMessageLogger(local_80,(char *)0x0,0,(char *)0x0);
        local_50 = (QDebug *)QMessageLogger::debug(pQVar2);
        local_8 = 0;
        local_4c = local_50;
        QDebug::operator<<(local_50,(char *)pQVar3);
        local_8 = 0xffffffff;
        QDebug::~QDebug(local_54);
        FUN_01202500(0);
      }
      else if (local_38._1_1_ == '\x02') {
        pQVar3 = local_60;
        pQVar2 = (QMessageLogger *)
                 QMessageLogger::QMessageLogger(local_94,(char *)0x0,0,(char *)0x0);
        local_5c = (QDebug *)QMessageLogger::debug(pQVar2);
        local_8 = 1;
        local_58 = local_5c;
        QDebug::operator<<(local_5c,(char *)pQVar3);
        local_8 = 0xffffffff;
        QDebug::~QDebug(local_60);
        FUN_01202500(1);
        pcVar4 = "inBuffer[2]";
        pQVar3 = local_6c;
        pQVar2 = (QMessageLogger *)
                 QMessageLogger::QMessageLogger(local_a8,(char *)0x0,0,(char *)0x0);
        local_68 = (QDebug *)QMessageLogger::debug(pQVar2);
        local_8 = 2;
        local_64 = local_68;
        pQVar3 = QDebug::operator<<(local_68,(char *)pQVar3);
        QDebug::operator<<(pQVar3,(int)pcVar4);
        local_8 = 0xffffffff;
        QDebug::~QDebug(local_6c);
      }
      if (100 < local_38._2_1_) {
        local_38._0_3_ = CONCAT12(100,(undefined2)local_38);
      }
      local_40[0x71] = local_38 >> 0x10 & 0xff;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x11772f0 ===== */

void FUN_011772f0(void)

{
  undefined4 local_3c;
  int *local_38;
  void *local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  local_34 = malloc(0x20);
  if (local_34 != (void *)0x0) {
    memset(local_34,0,0x20);
    local_2d = 0;
    local_2e = 0xaa;
    FUN_011825d0(local_34,&local_2e,&local_2d,0);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_2f = 0xba;
    local_3c = 0x20;
    local_30 = (**(code **)(*local_38 + 0x150))(local_34,&local_2c,&local_3c,&local_2f);
    free(local_34);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1177620 ===== */

void FUN_01177620(void)

{
  undefined4 local_40;
  uint local_3c;
  int *local_38;
  void *local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  char local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  local_34 = malloc(0x20);
  if (local_34 != (void *)0x0) {
    memset(local_34,0,0x20);
    local_2e = 0x18;
    local_2f = 0xa4;
    FUN_011825d0(local_34,&local_2f,&local_2e,0x89c);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_30 = 0xba;
    local_40 = 0x20;
    local_2d = (**(code **)(*local_38 + 0x150))(local_34,&local_2c,&local_40,&local_30);
    free(local_34);
    if (local_2d == '\0') {
      local_3c = 0xffffffff;
    }
    else {
      *(undefined1 *)(local_38 + 0x128) = local_28._1_1_;
      local_3c = (uint)*(byte *)(local_38 + 0x128);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1177730 ===== */

void FUN_01177730(void)

{
  undefined4 local_40;
  uint local_3c;
  int *local_38;
  void *local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  char local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  local_34 = malloc(0x20);
  if (local_34 != (void *)0x0) {
    memset(local_34,0,0x20);
    local_2e = 0x18;
    local_2f = 0xa4;
    FUN_011825d0(local_34,&local_2f,&local_2e,0x89c);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_30 = 0xba;
    local_40 = 0x20;
    local_2d = (**(code **)(*local_38 + 0x150))(local_34,&local_2c,&local_40,&local_30);
    free(local_34);
    if (local_2d == '\0') {
      local_3c = 0xffffffff;
    }
    else {
      *(undefined1 *)((int)local_38 + 0x4a1) = local_28._2_1_;
      local_3c = (uint)*(byte *)((int)local_38 + 0x4a1);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1124860 ===== */

void FUN_01124860(void)

{
  undefined4 local_40;
  int *local_3c;
  undefined1 local_35;
  void *local_34;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  local_34 = malloc(0x20);
  if (local_34 != (void *)0x0) {
    memset(local_34,0,0x20);
    local_2d = 0x18;
    local_2e = 0xa4;
    FUN_011825d0(local_34,&local_2e,&local_2d,0x8ac);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_2f = 0xba;
    local_40 = 0x20;
    local_35 = (**(code **)(*local_3c + 0x150))(local_34,&local_2c,&local_40,&local_2f);
    free(local_34);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1177840 ===== */

undefined4 FUN_01177840(void)

{
  return 0xaa0;
}


/* ===== 0x1124940 ===== */

void FUN_01124940(void)

{
  undefined4 local_3c;
  int *local_38;
  void *local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  local_34 = malloc(0x20);
  if (local_34 != (void *)0x0) {
    memset(local_34,0,0x20);
    local_2d = 0x18;
    local_2e = 0xa4;
    FUN_011825d0(local_34,&local_2e,&local_2d,0x884);
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_2f = 0xba;
    local_3c = 0x20;
    local_30 = (**(code **)(*local_38 + 0x150))(local_34,&local_2c,&local_3c,&local_2f);
    free(local_34);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x112c090 ===== */

void FUN_0112c090(void)

{
  uint uVar1;
  int iVar2;
  bool *pbVar3;
  QString local_70 [4];
  QString *local_6c;
  QString *local_68;
  QString local_64 [4];
  QString *local_60;
  QString *local_5c;
  QString local_58 [4];
  QString *local_54;
  QString *local_50;
  undefined4 local_4c;
  int *local_48;
  undefined1 *local_44;
  int local_40;
  char local_3a;
  undefined1 local_39;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01231a22;
  local_10 = ExceptionList;
  uVar1 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  local_44 = malloc(0x20);
  if (local_44 == (undefined1 *)0x0) {
    iVar2 = -1;
  }
  else {
    memset(local_44,0,0x20);
    *local_44 = 0xb0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_39 = 0xba;
    local_4c = 0x20;
    local_3a = (**(code **)(*local_48 + 0x150))(local_44,&local_38,&local_4c,&local_39,uVar1);
    free(local_44);
    if (local_3a == '\0') {
      iVar2 = -1;
    }
    else {
      local_40 = 0;
      if (local_38._2_1_ == 0) {
        iVar2 = 10;
        pbVar3 = (bool *)0x0;
        local_6c = (QString *)QString::number((int)local_70,local_38 >> 8 & 0xff);
        local_8 = 2;
        local_68 = local_6c;
        local_40 = QString::toInt(local_6c,pbVar3,iVar2);
        local_8 = 0xffffffff;
        QString::~QString(local_70);
      }
      else {
        iVar2 = 10;
        pbVar3 = (bool *)0x0;
        local_54 = (QString *)QString::number((int)local_58,(uint)local_38._2_1_);
        local_8 = 0;
        local_50 = local_54;
        local_40 = QString::toInt(local_54,pbVar3,iVar2);
        local_40 = local_40 * 100;
        local_8 = 0xffffffff;
        QString::~QString(local_58);
        iVar2 = 10;
        pbVar3 = (bool *)0x0;
        local_60 = (QString *)QString::number((int)local_64,local_38 >> 8 & 0xff);
        local_8 = 1;
        local_5c = local_60;
        iVar2 = QString::toInt(local_60,pbVar3,iVar2);
        local_40 = iVar2 + local_40;
        local_8 = 0xffffffff;
        QString::~QString(local_64);
      }
      local_48[0x79] = local_40;
      iVar2 = local_40 >> 0x1f;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,iVar2);
  return;
}


/* ===== 0x1177850 ===== */

/* WARNING: Type propagation algorithm not settling */

void FUN_01177850(void)

{
  uint uVar1;
  undefined1 auStack_bc [4];
  undefined1 auStack_b8 [4];
  undefined1 auStack_b4 [4];
  undefined1 auStack_b0 [4];
  undefined1 auStack_ac [4];
  undefined1 auStack_a8 [4];
  undefined1 auStack_a4 [4];
  undefined1 auStack_a0 [4];
  uint auStack_9c [5];
  uint uStack_88;
  uint auStack_84 [3];
  uint auStack_78 [3];
  uint auStack_6c [3];
  int *local_60;
  int iStack_5c;
  int local_58;
  void *local_54;
  undefined1 local_4d;
  char cStack_4c;
  char local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  undefined4 uStack_48;
  undefined4 local_44;
  uint local_40;
  undefined1 local_3c [4];
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01236f71;
  local_10 = ExceptionList;
  local_14 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_40 = 0;
  FUN_00fc1060(local_14);
  local_8 = 0;
  local_54 = malloc(0x20);
  if (local_54 == (void *)0x0) {
    FUN_00fef880(local_3c);
    local_40 = local_40 | 1;
    local_8 = 0xffffffff;
    FUN_00fc1420();
  }
  else {
    memset(local_54,0,0x20);
    local_4d = 0x18;
    local_49 = 0xa4;
    FUN_011825d0(local_54,&local_49,&local_4d,0x8c0);
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_4a = 0xba;
    auStack_6c[2] = 0x20;
    local_4b = (**(code **)(*local_60 + 0x150))(local_54,&local_38,auStack_6c + 2,&local_4a);
    if (local_4b == '\0') {
      FUN_00fef880(local_3c);
      local_40 = local_40 | 1;
      local_8 = 0xffffffff;
      FUN_00fc1420();
    }
    else {
      local_44 = 0xffffffff;
      local_58 = (local_34 & 0xff) - 1;
      switch(local_34 & 0xff) {
      case 1:
        local_44 = 0;
        break;
      case 2:
        local_44 = 1;
        break;
      default:
        FUN_00fc1060();
        local_40 = local_40 | 1;
        local_8 = 0xffffffff;
        FUN_00fc1420();
        goto LAB_01177c69;
      case 4:
        local_44 = 2;
        break;
      case 8:
        local_44 = 3;
        break;
      case 0x10:
        local_44 = 4;
        break;
      case 0x18:
        local_44 = 5;
        break;
      case 0x20:
        local_44 = 6;
      }
      auStack_6c[1] = 0;
      FUN_00fc5810(auStack_a0,auStack_6c + 1,&local_44);
      uStack_48 = 0xffffffff;
      uVar1 = local_34 >> 8 & 0xff;
      iStack_5c = uVar1 - 1;
      switch(uVar1) {
      case 1:
        uStack_48 = 0;
        break;
      case 2:
        uStack_48 = 1;
        break;
      default:
        FUN_00fc1060();
        local_40 = local_40 | 1;
        local_8 = 0xffffffff;
        FUN_00fc1420();
        goto LAB_01177c69;
      case 4:
        uStack_48 = 2;
        break;
      case 8:
        uStack_48 = 3;
        break;
      case 0x10:
        uStack_48 = 4;
        break;
      case 0x18:
        uStack_48 = 5;
        break;
      case 0x20:
        uStack_48 = 6;
      }
      auStack_6c[0] = 1;
      FUN_00fc5810(auStack_a4,auStack_6c,&uStack_48);
      auStack_78[2] = local_34 >> 0x10 & 0xff;
      auStack_78[1] = 2;
      FUN_00fc5810(auStack_a8,auStack_78 + 1,auStack_78 + 2);
      auStack_9c[0] = local_34._3_1_ & 1 ^ 1;
      auStack_84[2] = (int)(local_34._3_1_ & 2) >> 1 ^ 1;
      auStack_78[0] = 3;
      FUN_00fc5810(auStack_ac,auStack_78,auStack_9c);
      auStack_84[1] = 4;
      FUN_00fc5810(auStack_b0,auStack_84 + 1,auStack_84 + 2);
      cStack_4c = (char)local_30;
      auStack_9c[4] = local_30 >> 8 & 0xff;
      auStack_84[0] = (uint)(char)local_30;
      uStack_88 = 6;
      FUN_00fc5810(auStack_b4,&uStack_88,auStack_84);
      auStack_9c[3] = 5;
      FUN_00fc5810(auStack_b8,auStack_9c + 3,auStack_9c + 4);
      auStack_9c[2] = 0;
      auStack_9c[1] = 7;
      FUN_00fc5810(auStack_bc,auStack_9c + 1,auStack_9c + 2);
      FUN_00fef880(local_3c);
      local_40 = local_40 | 1;
      local_8 = 0xffffffff;
      FUN_00fc1420();
    }
  }
LAB_01177c69:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1177d10 ===== */

void FUN_01177d10(void)

{
  uint uVar1;
  undefined1 local_a0 [8];
  uint local_98;
  uint local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 local_88 [4];
  uint local_84;
  int *local_80;
  int local_7c;
  undefined1 local_76;
  undefined1 local_75;
  undefined1 local_74;
  undefined1 local_73;
  undefined1 local_72;
  undefined1 local_71;
  void *local_70;
  char local_69;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01236fa4;
  local_10 = ExceptionList;
  uVar1 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_84 = 0;
  local_14 = uVar1;
  local_70 = malloc(0x20);
  memset(local_70,0,0x20);
  local_71 = 0x18;
  local_72 = 0xa4;
  FUN_011825d0(local_70,&local_72,&local_71,0x888);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_73 = 0xba;
  local_8c = 0x20;
  local_69 = (**(code **)(*local_80 + 0x150))(local_70,&local_38,&local_8c,&local_73,uVar1);
  if (local_69 == '\0') {
    free(local_70);
    FUN_00fb8560();
    local_84 = local_84 | 1;
  }
  else {
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    memcpy(&local_50,&local_34,0x18);
    memset(local_70,0,0x20);
    memset(&local_38,0,0x21);
    local_74 = 0x18;
    local_75 = 0xa4;
    FUN_011825d0(local_70,&local_75,&local_74,0x8c8);
    local_76 = 0xba;
    local_90 = 0x20;
    local_69 = (**(code **)(*local_80 + 0x150))(local_70,&local_38,&local_90,&local_76);
    if (local_69 == '\0') {
      free(local_70);
      FUN_00fb8560();
      local_84 = local_84 | 1;
    }
    else {
      local_68 = 0;
      local_64 = 0;
      local_60 = 0;
      local_5c = 0;
      local_58 = 0;
      local_54 = 0;
      memcpy(&local_68,&local_34,0x18);
      free(local_70);
      FUN_00fb8560();
      local_8 = 0;
      for (local_7c = 0; local_7c < 0xd; local_7c = local_7c + 2) {
        local_98 = (uint)CONCAT11(*(undefined1 *)((int)&local_50 + local_7c + 1),
                                  *(undefined1 *)((int)&local_50 + local_7c));
        local_94 = (uint)CONCAT11(*(undefined1 *)((int)&local_68 + local_7c + 1),
                                  *(undefined1 *)((int)&local_68 + local_7c));
        FUN_00fc13f0(local_98,local_94);
        FUN_010d0600(local_a0);
      }
      FUN_00ff62d0(local_88);
      local_84 = local_84 | 1;
      local_8 = 0xffffffff;
      FUN_00fe12b0();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1177fe0 ===== */

void FUN_01177fe0(int *param_1)

{
  char cVar1;
  QMessageLogger *this;
  QDebug *pQVar2;
  QMessageLogger local_e4 [20];
  QDebug local_d0 [4];
  QDebug *local_cc;
  QDebug *local_c8;
  undefined4 local_c4;
  int *local_c0;
  undefined1 local_bc;
  undefined1 local_bb;
  undefined1 local_ba;
  char local_b9;
  undefined1 local_b8 [7];
  undefined1 uStack_b1;
  undefined1 uStack_b0;
  undefined1 uStack_af;
  undefined1 uStack_ae;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01236fd8;
  local_10 = ExceptionList;
  local_14 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*param_1 < 8) {
    memset(local_b8,0,0x80);
    local_ba = 4;
    local_bb = 0xa5;
    FUN_011825d0(local_b8,&local_bb,&local_ba,0x898);
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    cVar1 = FUN_01182530(&local_38,0x898);
    if (cVar1 == '\0') {
      pQVar2 = local_d0;
      this = (QMessageLogger *)QMessageLogger::QMessageLogger(local_e4,(char *)0x0,0,(char *)0x0);
      local_cc = (QDebug *)QMessageLogger::debug(this);
      local_8 = 0;
      local_c8 = local_cc;
      QDebug::operator<<(local_cc,(char *)pQVar2);
      local_8 = 0xffffffff;
      QDebug::~QDebug(local_d0);
    }
    else {
      uStack_b1 = (undefined1)*param_1;
      uStack_b0 = local_34._1_1_;
      uStack_af = local_34._2_1_;
      uStack_ae = local_34._3_1_;
      cVar1 = (**(code **)(*local_c0 + 0x148))();
      if (cVar1 != '\0') {
        local_bc = 0xba;
        local_c4 = 0x20;
        local_b9 = (**(code **)(*local_c0 + 0x14c))(local_b8,&local_c4,&local_bc);
        if (local_b9 != '\0') {
          local_c0[0x7c] = *param_1;
        }
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1178220 ===== */

void FUN_01178220(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined1 *puVar7;
  undefined4 local_cc;
  uint local_c8;
  int local_c4;
  int local_c0;
  undefined1 local_bc [8];
  int local_b4;
  int local_b0;
  int local_a8;
  undefined1 local_a3;
  undefined1 local_a2;
  undefined1 local_a1;
  undefined1 local_a0;
  undefined1 local_9f;
  undefined1 local_9e;
  undefined1 local_9d;
  int *local_9c;
  int local_98;
  char local_94 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01237021;
  local_10 = ExceptionList;
  uVar2 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  memset(local_94,0,0x80);
  local_9d = 0x10;
  local_9e = 0xa5;
  cVar1 = FUN_011825d0(local_94,&local_9e,&local_9d,0x888);
  if (cVar1 != '\0') {
    puVar7 = local_bc;
    FUN_00fb9e10(puVar7,uVar2);
    FUN_011c4290();
    FUN_01070b20();
    FUN_0101f640(puVar7);
    local_8 = 0;
    local_98 = 7;
    local_b4 = 0;
    FUN_00fb8560();
    local_8._0_1_ = 1;
    FUN_00fb8560();
    local_8 = CONCAT31(local_8._1_3_,2);
    local_a8 = 0;
    while (iVar3 = FUN_00fc0ae0(), local_a8 < iVar3) {
      pcVar4 = (char *)FUN_01026ce0(local_a8);
      if (*pcVar4 == '\0') {
        uVar5 = FUN_00fe16c0(local_a8);
        FUN_00fe75e0(uVar5);
        local_b4 = local_b4 + 1;
      }
      else {
        uVar5 = FUN_00fe16c0(local_a8);
        FUN_00fe75e0(uVar5);
        piVar6 = (int *)FUN_00fe16c0(local_a8);
        local_c4 = *piVar6 / 0x32;
        local_94[local_98] = (char)local_c4;
        local_94[local_98 + 1] = (char)((uint)local_c4 >> 8);
        local_98 = local_98 + 2;
      }
      local_a8 = local_a8 + 1;
    }
    for (local_b0 = 0; local_b0 < local_b4; local_b0 = local_b0 + 1) {
      uVar5 = FUN_00fe8400(local_b0);
      FUN_00fe75e0(uVar5);
      piVar6 = (int *)FUN_00fe8400(local_b0);
      local_94[local_98] = (char)(*piVar6 / 0x32);
      local_98 = local_98 + 1;
      piVar6 = (int *)FUN_00fe8400(local_b0);
      local_94[local_98] = (char)((uint)(*piVar6 / 0x32) >> 8);
      local_98 = local_98 + 1;
    }
    local_94[local_98] = '\x06' - (char)local_b4;
    local_c8 = local_98 + 1;
    local_98 = local_98 + 2;
    if (0x7f < local_c8) {
      ___report_rangecheckfailure();
    }
    local_94[local_c8] = '\0';
    local_c0 = (**(code **)(*local_9c + 0x38))();
    if (6 - local_b4 < local_c0) {
      local_c0 = 6 - local_b4;
      cVar1 = (**(code **)(*local_9c + 0xac))(&local_c0);
      if (cVar1 == '\0') {
        local_9f = 0;
        local_8._0_1_ = 1;
        FUN_00fb86c0();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00fb86c0();
        local_8 = 0xffffffff;
        FUN_01022fa0();
        goto LAB_011786be;
      }
    }
    cVar1 = (**(code **)(*local_9c + 0x148))();
    if (cVar1 == '\0') {
      local_a0 = 0;
      local_8._0_1_ = 1;
      FUN_00fb86c0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00fb86c0();
      local_8 = 0xffffffff;
      FUN_01022fa0();
    }
    else {
      local_a1 = 0xba;
      local_cc = 0x20;
      local_a3 = (**(code **)(*local_9c + 0x14c))(local_94,&local_cc,&local_a1);
      local_8._0_1_ = 1;
      local_a2 = local_a3;
      FUN_00fb86c0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00fb86c0();
      local_8 = 0xffffffff;
      FUN_01022fa0();
    }
  }
LAB_011786be:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x11786e0 ===== */

void FUN_011786e0(undefined4 *param_1)

{
  char cVar1;
  uint uVar2;
  QMessageLogger *this;
  QDebug *pQVar3;
  QMessageLogger local_f4 [20];
  QDebug local_e0 [4];
  QDebug *local_dc;
  QDebug *local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined1 local_c7;
  undefined1 local_c6;
  undefined1 local_c5;
  undefined4 local_c4;
  char local_bd;
  int *local_bc;
  undefined1 local_b8 [7];
  undefined1 uStack_b1;
  undefined1 uStack_b0;
  undefined1 uStack_af;
  undefined1 uStack_ae;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01237055;
  local_10 = ExceptionList;
  uVar2 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  memset(local_b8,0,0x80);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  cVar1 = FUN_01182530(&local_38,0x880);
  if (cVar1 == '\0') {
    pQVar3 = local_e0;
    this = (QMessageLogger *)QMessageLogger::QMessageLogger(local_f4,(char *)0x0,0,(char *)0x0);
    local_dc = (QDebug *)QMessageLogger::debug(this);
    local_8 = 0;
    local_d8 = local_dc;
    QDebug::operator<<(local_dc,(char *)pQVar3);
    local_8 = 0xffffffff;
    QDebug::~QDebug(local_e0);
  }
  else {
    local_c5 = 4;
    local_c6 = 0xa5;
    FUN_011825d0(local_b8,&local_c6,&local_c5,0x880);
    uStack_b1 = (undefined1)local_34;
    uStack_b0 = local_34._1_1_;
    uStack_af = local_34._2_1_;
    uStack_ae = local_34._3_1_;
    if ((char)local_bc[0x77] == '\0') {
      local_c4 = 0;
      local_d0 = *param_1;
      switch(local_d0) {
      case 0:
        local_c4 = 8;
        break;
      case 1:
        local_c4 = 4;
        break;
      case 2:
        local_c4 = 2;
        break;
      case 3:
        local_c4 = 1;
        break;
      case 4:
        local_c4 = 0x84;
        break;
      case 5:
        local_c4 = 0x82;
        break;
      case 6:
        local_c4 = 0x81;
      }
      if ((char)local_bc[0x6f] == -1) {
        if (local_bc[0x7a] <= local_bc[0x78]) {
          uStack_af = (undefined1)local_c4;
        }
        uStack_b1 = (undefined1)local_c4;
      }
      else {
        uStack_b1 = (undefined1)local_c4;
      }
    }
    else {
      local_cc = *param_1;
      switch(local_cc) {
      case 0:
        uStack_b0 = 0x88;
        break;
      case 1:
        uStack_b0 = 0x84;
        break;
      case 2:
        uStack_b0 = 0x82;
        break;
      case 3:
        uStack_b0 = 2;
        break;
      case 4:
        uStack_b0 = 8;
        break;
      case 5:
        uStack_b0 = 4;
        break;
      case 6:
        uStack_b0 = 2;
      }
    }
    cVar1 = (**(code **)(*local_bc + 0x148))(uVar2);
    if (cVar1 != '\0') {
      local_c7 = 0xba;
      local_d4 = 0x20;
      local_bd = (**(code **)(*local_bc + 0x14c))(local_b8,&local_d4,&local_c7);
      if (local_bd != '\0') {
        *(undefined1 *)((int)local_bc + 0x483) = uStack_b1;
        *(undefined1 *)(local_bc + 0x121) = uStack_b0;
        *(undefined1 *)((int)local_bc + 0x485) = uStack_af;
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1178b40 ===== */

/* WARNING: Removing unreachable block (ram,0x01178c37) */

void FUN_01178b40(undefined4 *param_1)

{
  char cVar1;
  QMessageLogger *this;
  QDebug *pQVar2;
  QMessageLogger local_ec [20];
  QDebug local_d8 [4];
  QDebug *local_d4;
  QDebug *local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  int *local_c0;
  undefined1 local_bc;
  undefined1 local_bb;
  undefined1 local_ba;
  char local_b9;
  undefined1 local_b8 [7];
  undefined1 uStack_b1;
  undefined1 uStack_b0;
  undefined1 uStack_af;
  undefined1 uStack_ae;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01237089;
  local_10 = ExceptionList;
  local_14 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  memset(local_b8,0,0x80);
  local_ba = 4;
  local_bb = 0xa5;
  FUN_011825d0(local_b8,&local_bb,&local_ba,0x898);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  cVar1 = FUN_01182530(&local_38,0x898);
  if (cVar1 == '\0') {
    pQVar2 = local_d8;
    this = (QMessageLogger *)QMessageLogger::QMessageLogger(local_ec,(char *)0x0,0,(char *)0x0);
    local_d4 = (QDebug *)QMessageLogger::debug(this);
    local_8 = 0;
    local_d0 = local_d4;
    QDebug::operator<<(local_d4,(char *)pQVar2);
    local_8 = 0xffffffff;
    QDebug::~QDebug(local_d8);
  }
  else {
    local_c4 = *param_1;
    switch(local_c4) {
    case 0:
      local_c8 = 8;
      uStack_b0 = 0;
      break;
    case 1:
      uStack_b0 = 1;
      break;
    case 2:
      uStack_b0 = 2;
      break;
    case 3:
      uStack_b0 = 3;
      break;
    case 4:
      uStack_b0 = 4;
      break;
    case 5:
      uStack_b0 = 5;
      break;
    default:
      goto switchD_01178c14_default;
    }
    uStack_b1 = (undefined1)local_34;
    uStack_af = local_34._2_1_;
    uStack_ae = local_34._3_1_;
    cVar1 = (**(code **)(*local_c0 + 0x148))();
    if (cVar1 != '\0') {
      local_bc = 0xba;
      local_cc = 0x20;
      local_b9 = (**(code **)(*local_c0 + 0x14c))(local_b8,&local_cc,&local_bc);
      if (local_b9 != '\0') {
        *(undefined1 *)(local_c0 + 0x127) = uStack_b0;
      }
    }
  }
switchD_01178c14_default:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1178e30 ===== */

void FUN_01178e30(int *param_1)

{
  int iVar1;
  char cVar2;
  QMessageLogger *this;
  QDebug *pQVar3;
  QMessageLogger local_ec [20];
  QDebug local_d8 [4];
  QDebug *local_d4;
  QDebug *local_d0;
  undefined4 local_cc;
  int local_c8;
  int *local_c4;
  undefined1 local_c0;
  undefined1 local_bf;
  undefined1 local_be;
  undefined1 local_bd;
  uint local_bc;
  undefined1 local_b8 [7];
  undefined1 uStack_b1;
  undefined1 uStack_b0;
  undefined1 uStack_af;
  undefined1 uStack_ae;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_012370bd;
  local_10 = ExceptionList;
  local_14 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = *param_1;
  if ((iVar1 == 0) || (iVar1 == 1)) {
    local_bc = 1;
  }
  else {
    local_bc = iVar1 / 2;
  }
  local_c8 = local_bc + -1;
  switch(local_c8) {
  case 0:
    local_bc = 4;
    break;
  case 1:
    local_bc = 3;
    break;
  case 2:
    local_bc = 2;
    break;
  case 3:
    local_bc = 1;
    break;
  case 4:
    local_bc = 0;
    break;
  default:
    local_bc = 2;
  }
  if (local_bc < 5) {
    memset(local_b8,0,0x80);
    local_bd = 4;
    local_be = 0xa5;
    FUN_011825d0(local_b8,&local_be,&local_bd,0x898);
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    cVar2 = FUN_01182530(&local_38,0x898);
    if (cVar2 == '\0') {
      pQVar3 = local_d8;
      this = (QMessageLogger *)QMessageLogger::QMessageLogger(local_ec,(char *)0x0,0,(char *)0x0);
      local_d4 = (QDebug *)QMessageLogger::debug(this);
      local_8 = 0;
      local_d0 = local_d4;
      QDebug::operator<<(local_d4,(char *)pQVar3);
      local_8 = 0xffffffff;
      QDebug::~QDebug(local_d8);
    }
    else {
      uStack_b1 = (undefined1)local_34;
      uStack_b0 = local_34._1_1_;
      uStack_af = (undefined1)local_bc;
      uStack_ae = local_34._3_1_;
      cVar2 = (**(code **)(*local_c4 + 0x148))();
      if (cVar2 != '\0') {
        local_bf = 0xba;
        local_cc = 0x20;
        local_c0 = (**(code **)(*local_c4 + 0x14c))(local_b8,&local_cc,&local_bf);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1179120 ===== */

void FUN_01179120(int *param_1)

{
  char cVar1;
  uint uVar2;
  QMessageLogger *pQVar3;
  QDebug *pQVar4;
  QMessageLogger local_108 [20];
  QMessageLogger local_f4 [20];
  QDebug local_e0 [4];
  QDebug *local_dc;
  QDebug *local_d8;
  undefined4 local_d4;
  QDebug local_d0 [4];
  QDebug *local_cc;
  QDebug *local_c8;
  int local_c4;
  int *local_c0;
  undefined1 local_bc;
  undefined1 local_bb;
  undefined1 local_ba;
  undefined1 local_b9;
  undefined1 local_b8 [7];
  undefined1 uStack_b1;
  undefined1 uStack_b0;
  undefined1 uStack_af;
  undefined1 uStack_ae;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_012370fd;
  local_10 = ExceptionList;
  uVar2 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*param_1 == 0) {
    local_c4 = *param_1;
  }
  else {
    local_c4 = *param_1 + -1;
  }
  local_14 = uVar2;
  if ((local_c4 < 10) && (-1 < local_c4)) {
    memset(local_b8,0,0x80);
    local_b9 = 4;
    local_ba = 0xa5;
    FUN_011825d0(local_b8,&local_ba,&local_b9,0x898);
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    cVar1 = FUN_01182530(&local_38,0x898);
    if (cVar1 == '\0') {
      pQVar4 = local_e0;
      pQVar3 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_108,(char *)0x0,0,(char *)0x0)
      ;
      local_dc = (QDebug *)QMessageLogger::debug(pQVar3);
      local_8 = 1;
      local_d8 = local_dc;
      QDebug::operator<<(local_dc,(char *)pQVar4);
      local_8 = 0xffffffff;
      QDebug::~QDebug(local_e0);
    }
    else {
      uStack_b1 = (undefined1)local_34;
      uStack_b0 = local_34._1_1_;
      uStack_af = local_34._2_1_;
      uStack_ae = (undefined1)local_c4;
      cVar1 = (**(code **)(*local_c0 + 0x148))(uVar2);
      if (cVar1 != '\0') {
        local_bb = 0xba;
        local_d4 = 0x20;
        local_bc = (**(code **)(*local_c0 + 0x14c))(local_b8,&local_d4,&local_bb);
      }
    }
  }
  else {
    pQVar4 = local_d0;
    pQVar3 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_f4,(char *)0x0,0,(char *)0x0);
    local_cc = (QDebug *)QMessageLogger::debug(pQVar3);
    local_8 = 0;
    local_c8 = local_cc;
    QDebug::operator<<(local_cc,(char *)pQVar4);
    local_8 = 0xffffffff;
    QDebug::~QDebug(local_d0);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x11793d0 ===== */

void FUN_011793d0(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  QMessageLogger *this;
  QDebug *pQVar3;
  QMessageLogger local_114 [20];
  undefined4 local_100;
  QDebug local_fc [4];
  QDebug *local_f8;
  QDebug *local_f4;
  QString local_f0 [4];
  QString local_ec [4];
  QString local_e8 [4];
  QString local_e4 [4];
  QString local_e0 [4];
  QString local_dc [4];
  QString local_d8 [4];
  QString local_d4 [4];
  QString local_d0 [4];
  QString local_cc [4];
  QString local_c8 [4];
  QString local_c4 [4];
  QString local_c0 [4];
  QString local_bc [4];
  QString local_b8 [4];
  undefined4 local_b4;
  int local_b0;
  undefined4 local_ac;
  int local_a8;
  undefined1 local_a1;
  undefined1 local_a0;
  undefined1 local_9f;
  char local_9e;
  char local_9d;
  int *local_9c;
  uint local_98;
  undefined1 local_94 [7];
  undefined1 uStack_8d;
  undefined1 uStack_8c;
  undefined1 uStack_8b;
  undefined1 uStack_8a;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0123722a;
  local_10 = ExceptionList;
  local_14 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_98 = 0;
  QString::QString(local_c0,"r");
  local_8 = 0;
  local_98 = local_98 | 1;
  cVar1 = FUN_010529f0(local_c0);
  if (cVar1 != '\0') {
    QString::QString(local_bc,"b");
    local_8 = 1;
    local_98 = local_98 | 2;
    cVar1 = FUN_010529f0(local_bc);
    if (cVar1 != '\0') {
      QString::QString(local_b8,"b");
      local_8 = 2;
      local_98 = local_98 | 4;
      cVar1 = FUN_010529f0(local_b8);
      if ((cVar1 != '\0') && (param_2 < 3)) {
        local_b4 = 0;
        goto LAB_011794e2;
      }
    }
  }
  local_b4 = 1;
LAB_011794e2:
  local_9e = (char)local_b4;
  local_8 = 1;
  if ((local_98 & 4) != 0) {
    local_98 = local_98 & 0xfffffffb;
    QString::~QString(local_b8);
  }
  local_8 = 0;
  if ((local_98 & 2) != 0) {
    local_98 = local_98 & 0xfffffffd;
    QString::~QString(local_bc);
  }
  local_8 = 0xffffffff;
  if ((local_98 & 1) != 0) {
    local_98 = local_98 & 0xfffffffe;
    QString::~QString(local_c0);
  }
  if (local_9e == '\0') {
    local_a8 = param_2;
    if (param_2 == 0) {
      local_ac = 0x8b8;
    }
    else if (param_2 == 1) {
      local_ac = 0x8b9;
    }
    else if (param_2 == 2) {
      local_ac = 0x8ca;
    }
    memset(local_94,0,0x80);
    local_9f = 4;
    local_a0 = 0xa5;
    FUN_011825d0(local_94,&local_a0,&local_9f,local_ac);
    QString::QString(local_c4,"r");
    local_8 = 4;
    uStack_8d = FUN_010f3870(local_c4);
    local_8 = 0xffffffff;
    QString::~QString(local_c4);
    QString::QString(local_c8,"g");
    local_8 = 5;
    uStack_8c = FUN_010f3870(local_c8);
    local_8 = 0xffffffff;
    QString::~QString(local_c8);
    QString::QString(local_cc,"b");
    local_8 = 6;
    uStack_8b = FUN_010f3870(local_cc);
    local_8 = 0xffffffff;
    QString::~QString(local_cc);
    uStack_8a = 0xff;
    cVar1 = (**(code **)(*local_9c + 0x148))();
    if (cVar1 != '\0') {
      local_a1 = 0xba;
      local_100 = 0x20;
      local_9d = (**(code **)(*local_9c + 0x14c))(local_94,&local_100,&local_a1);
      if (local_9d != '\0') {
        local_b0 = param_2;
        if (param_2 == 0) {
          QString::QString(local_d0,"b");
          local_8 = 7;
          uVar2 = FUN_010f3870(local_d0);
          *(undefined1 *)((int)local_9c + 0x4bd) = uVar2;
          local_8 = 0xffffffff;
          QString::~QString(local_d0);
          QString::QString(local_d4,"g");
          local_8 = 8;
          uVar2 = FUN_010f3870(local_d4);
          *(undefined1 *)(local_9c + 0x12f) = uVar2;
          local_8 = 0xffffffff;
          QString::~QString(local_d4);
          QString::QString(local_d8,"r");
          local_8 = 9;
          uVar2 = FUN_010f3870(local_d8);
          *(undefined1 *)((int)local_9c + 0x4bb) = uVar2;
          local_8 = 0xffffffff;
          QString::~QString(local_d8);
        }
        else if (param_2 == 1) {
          QString::QString(local_dc,"b");
          local_8 = 10;
          uVar2 = FUN_010f3870(local_dc);
          *(undefined1 *)((int)local_9c + 0x4c1) = uVar2;
          local_8 = 0xffffffff;
          QString::~QString(local_dc);
          QString::QString(local_e0,"g");
          local_8 = 0xb;
          uVar2 = FUN_010f3870(local_e0);
          *(undefined1 *)(local_9c + 0x130) = uVar2;
          local_8 = 0xffffffff;
          QString::~QString(local_e0);
          QString::QString(local_e4,"r");
          local_8 = 0xc;
          uVar2 = FUN_010f3870(local_e4);
          *(undefined1 *)((int)local_9c + 0x4bf) = uVar2;
          local_8 = 0xffffffff;
          QString::~QString(local_e4);
        }
        else if (param_2 == 2) {
          QString::QString(local_e8,"b");
          local_8 = 0xd;
          uVar2 = FUN_010f3870(local_e8);
          *(undefined1 *)((int)local_9c + 0x4c5) = uVar2;
          local_8 = 0xffffffff;
          QString::~QString(local_e8);
          QString::QString(local_ec,"g");
          local_8 = 0xe;
          uVar2 = FUN_010f3870(local_ec);
          *(undefined1 *)(local_9c + 0x131) = uVar2;
          local_8 = 0xffffffff;
          QString::~QString(local_ec);
          QString::QString(local_f0,"r");
          local_8 = 0xf;
          uVar2 = FUN_010f3870(local_f0);
          *(undefined1 *)((int)local_9c + 0x4c3) = uVar2;
          local_8 = 0xffffffff;
          QString::~QString(local_f0);
        }
      }
    }
  }
  else {
    pQVar3 = local_fc;
    this = (QMessageLogger *)QMessageLogger::QMessageLogger(local_114,(char *)0x0,0,(char *)0x0);
    local_f8 = (QDebug *)QMessageLogger::debug(this);
    local_8 = 3;
    local_f4 = local_f8;
    QDebug::operator<<(local_f8,(char *)pQVar3);
    local_8 = 0xffffffff;
    QDebug::~QDebug(local_fc);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x117bb00 ===== */

undefined4 FUN_0117bb00(undefined4 *param_1)

{
  char cVar1;
  int *in_ECX;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 local_c;
  int *local_8;
  
  local_c = *param_1;
  local_8 = in_ECX;
  switch(local_c) {
  case 0:
    uStack_10 = 100;
    cVar1 = (**(code **)(*in_ECX + 0xdc))(&uStack_10);
    if (cVar1 == '\0') {
      return 0;
    }
    uStack_14 = 10;
    cVar1 = (**(code **)(*local_8 + 0xc0))(&uStack_14,0);
    if (cVar1 == '\0') {
      return 0;
    }
    uStack_18 = 4;
    cVar1 = (**(code **)(*local_8 + 0xb8))(&uStack_18,1);
    if (cVar1 == '\0') {
      return 0;
    }
    cVar1 = (**(code **)(*local_8 + 0xfc))(0);
    if (cVar1 == '\0') {
      return 0;
    }
    uStack_1c = 1;
    cVar1 = (**(code **)(*local_8 + 0xe0))(&uStack_1c);
    if (cVar1 == '\0') {
      return 0;
    }
    break;
  case 1:
    uStack_20 = 0x50;
    cVar1 = (**(code **)(*in_ECX + 0xdc))(&uStack_20);
    if (cVar1 == '\0') {
      return 0;
    }
    uStack_24 = 8;
    cVar1 = (**(code **)(*local_8 + 0xc0))(&uStack_24,0);
    if (cVar1 == '\0') {
      return 0;
    }
    uStack_28 = 4;
    cVar1 = (**(code **)(*local_8 + 0xb8))(&uStack_28,1);
    if (cVar1 == '\0') {
      return 0;
    }
    cVar1 = (**(code **)(*local_8 + 0xfc))(1);
    if (cVar1 == '\0') {
      return 0;
    }
    uStack_2c = 1;
    cVar1 = (**(code **)(*local_8 + 0xe0))(&uStack_2c);
    if (cVar1 == '\0') {
      return 0;
    }
    break;
  case 2:
    uStack_30 = 0;
    cVar1 = (**(code **)(*in_ECX + 0xb8))(&uStack_30,1);
    if (cVar1 == '\0') {
      return 0;
    }
    uStack_34 = 9;
    cVar1 = (**(code **)(*local_8 + 0xe0))(&uStack_34);
    if (cVar1 == '\0') {
      return 0;
    }
    break;
  case 3:
    break;
  default:
    return 0;
  }
  return 1;
}


/* ===== 0x112a740 ===== */

void FUN_0112a740(int *param_1,int *param_2,QVariant *param_3)

{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  QMessageLogger *pQVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  QDebug *pQVar11;
  QMessageLogger local_1c8 [20];
  QMessageLogger local_1b4 [28];
  undefined1 local_198 [4];
  QDebug *local_194;
  undefined4 local_190;
  QDebug local_18c [4];
  undefined4 uStack_188;
  QDebug *local_184;
  QDebug local_180 [4];
  QDebug *local_17c;
  QDebug *local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  undefined4 local_108 [2];
  undefined1 local_100 [4];
  undefined4 local_fc;
  int local_f8;
  int local_f4;
  char local_ee;
  undefined1 local_ed;
  undefined1 local_ec;
  undefined1 local_eb;
  byte local_ea;
  undefined1 local_e9;
  int local_e8;
  char local_e1;
  int local_dc;
  undefined1 *local_d8;
  int *local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 local_98 [4];
  undefined1 local_94 [7];
  undefined1 local_8d [121];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0123183a;
  local_10 = ExceptionList;
  uVar2 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  local_d0 = 0;
  local_cc = 2;
  local_c8 = 1;
  local_c4 = 5;
  local_c0 = 6;
  local_bc = 7;
  local_b8 = 8;
  local_b4 = 9;
  local_b0 = 10;
  local_ac = 0xb;
  local_a8 = 0xc;
  local_a4 = 0x8e;
  local_a0 = 0x8f;
  local_9c = 0xd;
  local_14 = uVar2;
  puVar3 = (undefined4 *)FUN_00fc13f0(&local_d0,local_98);
  FUN_00fc12b0(*puVar3,puVar3[1]);
  local_8._0_1_ = 2;
  local_10c = 0;
  local_f4 = 0;
  while (iVar4 = FUN_00fc0ae0(uVar2), local_f4 < iVar4) {
    piVar5 = (int *)FUN_00fe8400(local_f4);
    if (*piVar5 == *param_1) {
      local_10c = local_f4;
    }
    local_f4 = local_f4 + 1;
  }
  FUN_00fc1060();
  local_8._0_1_ = 3;
  puVar9 = local_100;
  FUN_00fb9e10(puVar9);
  FUN_011c4290();
  FUN_01070b60();
  FUN_01040b60(puVar9);
  local_8._0_1_ = 4;
  local_f8 = 0;
  while (iVar4 = FUN_00ff83e0(), local_f8 < iVar4) {
    FUN_00ffc860(local_f8);
    local_108[0] = FUN_0104d480();
    local_16c = FUN_01033710();
    FUN_00fc5810(local_198,&local_16c,local_108);
    local_f8 = local_f8 + 1;
  }
  if ((*param_1 == 0) && (*param_2 != 0xb9)) {
    local_190 = 0;
    cVar1 = (**(code **)(*local_d4 + 0xf0))(&local_190);
    if (cVar1 == '\0') {
      local_e9 = 0;
      local_8._0_1_ = 3;
      FUN_00ff63a0();
      local_8._0_1_ = 2;
      FUN_00fc1420();
      local_8._0_1_ = 1;
      FUN_00fb86c0();
      local_8 = (uint)local_8._1_3_ << 8;
      QVariant::~QVariant((QVariant *)&stack0x00000010);
      local_8 = 0xffffffff;
      QVariant::~QVariant((QVariant *)&stack0x00000020);
      goto LAB_0112b4b8;
    }
  }
  local_ea = 4;
  memset(local_94,0,0x80);
  local_eb = 4;
  local_ec = 0xa5;
  FUN_011825d0(local_94,&local_ec,&local_eb,(uint)local_ea * local_10c + 0x600);
  local_d8 = local_8d;
  local_e8 = 0;
  while (iVar4 = FUN_00fc0ae0(), local_e8 < iVar4) {
    piVar5 = (int *)FUN_00fe8400(local_e8);
    if (*piVar5 != -1) {
      if ((*param_2 == 0x1d) && (piVar5 = (int *)FUN_00fe8400(local_e8), *piVar5 == *param_1)) {
        uVar10 = 0;
        uVar8 = 0;
        uVar2 = QVariant::toUInt(param_3,(bool *)0x0);
        FUN_011817e0(param_2,local_d8,uVar2,uVar8,uVar10);
      }
      else if ((*param_2 == 0x1b) && (piVar5 = (int *)FUN_00fe8400(local_e8), *piVar5 == *param_1))
      {
        uVar10 = 0;
        uVar8 = 0;
        uVar2 = QVariant::toUInt(param_3,(bool *)0x0);
        FUN_011817e0(param_2,local_d8,uVar2,uVar8,uVar10);
      }
      else if ((*param_2 == 0x2a) && (piVar5 = (int *)FUN_00fe8400(local_e8), *piVar5 == *param_1))
      {
        uVar8 = 0;
        uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
        uVar6 = QVariant::toUInt(param_3,(bool *)0x0);
        FUN_011817e0(param_2,local_d8,uVar6,uVar2,uVar8);
      }
      else {
        piVar5 = (int *)FUN_00fe8400(local_e8);
        if (*piVar5 == *param_1) {
          if (*param_2 == 0) {
            local_110 = *param_1;
            switch(local_110) {
            case 0:
              uStack_11c = 9;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              uVar6 = QVariant::toUInt(param_3,(bool *)0x0);
              FUN_011817e0(&uStack_11c,local_d8,uVar6,uVar2,uVar8);
              break;
            case 1:
              uStack_124 = 0xb;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              uVar6 = QVariant::toUInt(param_3,(bool *)0x0);
              FUN_011817e0(&uStack_124,local_d8,uVar6,uVar2,uVar8);
              break;
            case 2:
              uStack_120 = 10;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              uVar6 = QVariant::toUInt(param_3,(bool *)0x0);
              FUN_011817e0(&uStack_120,local_d8,uVar6,uVar2,uVar8);
              break;
            case 5:
              uStack_128 = 0x27;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              uVar6 = QVariant::toUInt(param_3,(bool *)0x0);
              FUN_011817e0(&uStack_128,local_d8,uVar6,uVar2,uVar8);
              break;
            case 7:
              uStack_12c = 0xe;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              uVar6 = QVariant::toUInt(param_3,(bool *)0x0);
              FUN_011817e0(&uStack_12c,local_d8,uVar6,uVar2,uVar8);
              break;
            case 8:
              uStack_130 = 0xf;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              uVar6 = QVariant::toUInt(param_3,(bool *)0x0);
              FUN_011817e0(&uStack_130,local_d8,uVar6,uVar2,uVar8);
              break;
            case 9:
              uStack_134 = 0x1b;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              uVar6 = QVariant::toUInt(param_3,(bool *)0x0);
              FUN_011817e0(&uStack_134,local_d8,uVar6,uVar2,uVar8);
              break;
            case 0xb:
              uStack_138 = 0x25;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              uVar6 = QVariant::toUInt(param_3,(bool *)0x0);
              FUN_011817e0(&uStack_138,local_d8,uVar6,uVar2,uVar8);
              break;
            case 0xc:
              uStack_13c = 0x26;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              uVar6 = QVariant::toUInt(param_3,(bool *)0x0);
              FUN_011817e0(&uStack_13c,local_d8,uVar6,uVar2,uVar8);
              break;
            case 0xd:
              uStack_140 = 0x24;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              uVar6 = QVariant::toUInt(param_3,(bool *)0x0);
              FUN_011817e0(&uStack_140,local_d8,uVar6,uVar2,uVar8);
            }
          }
          else if (*param_2 == 0xb9) {
            local_114 = *param_1;
            switch(local_114) {
            case 0:
              uStack_144 = 9;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              FUN_011817e0(&uStack_144,local_d8,1,uVar2,uVar8);
              break;
            case 1:
              uStack_14c = 0xb;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              FUN_011817e0(&uStack_14c,local_d8,1,uVar2,uVar8);
              break;
            case 2:
              uStack_148 = 10;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              FUN_011817e0(&uStack_148,local_d8,1,uVar2,uVar8);
              break;
            case 5:
              uStack_150 = 0x27;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              FUN_011817e0(&uStack_150,local_d8,1,uVar2,uVar8);
              break;
            case 6:
              uStack_154 = 0x28;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              FUN_011817e0(&uStack_154,local_d8,1,uVar2,uVar8);
              break;
            case 7:
              uStack_158 = 0xc;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              FUN_011817e0(&uStack_158,local_d8,1,uVar2,uVar8);
              break;
            case 8:
              uStack_15c = 0xd;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              FUN_011817e0(&uStack_15c,local_d8,1,uVar2,uVar8);
              break;
            case 9:
              uStack_160 = 0x1b;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              FUN_011817e0(&uStack_160,local_d8,1,uVar2,uVar8);
              break;
            case 0xb:
              uStack_164 = 0x25;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              FUN_011817e0(&uStack_164,local_d8,1,uVar2,uVar8);
              break;
            case 0xc:
              uStack_168 = 0x26;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              FUN_011817e0(&uStack_168,local_d8,1,uVar2,uVar8);
              break;
            case 0xd:
              uStack_188 = 0x24;
              uVar8 = 0;
              uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
              FUN_011817e0(&uStack_188,local_d8,1,uVar2,uVar8);
            }
          }
          else {
            uVar8 = 0;
            uVar2 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
            uVar6 = QVariant::toUInt(param_3,(bool *)0x0);
            FUN_011817e0(param_2,local_d8,uVar6,uVar2,uVar8);
          }
        }
      }
      local_170 = 0;
      puVar3 = &local_170;
      uVar8 = FUN_00fe8400(local_e8);
      local_fc = FUN_01000270(uVar8,puVar3);
      piVar5 = (int *)FUN_00fe8400(local_e8);
      if (*piVar5 == *param_1) {
        FUN_010333f0(*local_d8,0);
        FUN_010333a0(local_d8[1],0);
        FUN_01033350(local_d8[2],0);
        FUN_01033350(local_d8[3],0);
      }
    }
    local_e8 = local_e8 + 1;
  }
  local_ed = 0xba;
  local_174 = 0x20;
  local_e1 = (**(code **)(*local_d4 + 0x14c))(local_94,&local_174,&local_ed);
  if (local_e1 == '\0') {
    pQVar11 = local_18c;
    pQVar7 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_1c8,(char *)0x0,0,(char *)0x0);
    local_194 = (QDebug *)QMessageLogger::debug(pQVar7);
    local_8._0_1_ = 6;
    local_184 = local_194;
    QDebug::operator<<(local_194,(char *)pQVar11);
    local_8 = CONCAT31(local_8._1_3_,4);
    QDebug::~QDebug(local_18c);
  }
  else {
    FUN_010e3880(*local_d8,local_d8[2],local_d8[1],local_d8[3]);
    local_118 = *param_1;
    switch(local_118) {
    case 0:
      local_d4[0x7d] = local_dc;
      break;
    case 1:
      local_d4[0x7f] = local_dc;
      break;
    case 2:
      local_d4[0x7e] = local_dc;
      break;
    case 5:
      local_d4[0x80] = local_dc;
      break;
    case 6:
      local_d4[0x81] = local_dc;
      break;
    case 7:
      local_d4[0x82] = local_dc;
      break;
    case 8:
      local_d4[0x83] = local_dc;
      break;
    case 9:
      local_d4[0x84] = local_dc;
      break;
    case 10:
      local_d4[0x85] = local_dc;
      break;
    case 0xb:
      local_d4[0x86] = local_dc;
      break;
    case 0xc:
      local_d4[0x87] = local_dc;
      break;
    case 0xd:
      local_d4[0x8a] = local_dc;
    }
    pQVar11 = local_180;
    pQVar7 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_1b4,(char *)0x0,0,(char *)0x0);
    local_17c = (QDebug *)QMessageLogger::debug(pQVar7);
    local_8._0_1_ = 5;
    local_178 = local_17c;
    QDebug::operator<<(local_17c,(char *)pQVar11);
    local_8 = CONCAT31(local_8._1_3_,4);
    QDebug::~QDebug(local_180);
  }
  Sleep(local_d4[0x70]);
  local_ee = local_e1;
  local_8._0_1_ = 3;
  FUN_00ff63a0();
  local_8._0_1_ = 2;
  FUN_00fc1420();
  local_8._0_1_ = 1;
  FUN_00fb86c0();
  local_8 = (uint)local_8._1_3_ << 8;
  QVariant::~QVariant((QVariant *)&stack0x00000010);
  local_8 = 0xffffffff;
  QVariant::~QVariant((QVariant *)&stack0x00000020);
LAB_0112b4b8:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x117a8f0 ===== */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_0117a8f0(char param_1,int *param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  QMessageLogger *pQVar4;
  int *in_stack_00000020;
  QDebug *pQVar5;
  char *pcVar6;
  QMessageLogger local_112c [20];
  QMessageLogger local_1118 [40];
  undefined4 local_10f0;
  QDebug *local_10ec;
  QDebug *local_10e8;
  undefined4 local_10e4;
  undefined4 local_10e0;
  undefined4 local_10dc;
  QDebug local_10d8 [4];
  QDebug *local_10d4;
  QDebug *local_10d0;
  int local_10cc;
  undefined4 local_10c8;
  undefined4 local_10c4;
  QDebug local_10c0 [4];
  int local_10bc;
  uint local_10b8;
  undefined1 local_10b4 [4];
  int local_10b0;
  int local_10ac;
  uint local_10a8;
  int local_10a4;
  int local_10a0;
  int local_109c;
  int local_1098;
  uint local_1094;
  int local_1090;
  int local_108c;
  int local_1088;
  byte *local_1084;
  int local_1080;
  int local_107c;
  char local_1078;
  int local_1074;
  uint local_1070;
  undefined4 local_1068;
  int local_1064;
  uint local_1060;
  int local_105c;
  int local_1058;
  byte local_1051;
  undefined1 local_1050;
  undefined1 local_104f;
  undefined1 local_104e;
  undefined1 local_104d;
  byte local_104c;
  byte local_104b;
  byte local_104a;
  byte local_1049;
  int local_1048;
  int *local_1044;
  char local_103f;
  byte local_103e;
  byte local_103d;
  int local_103c;
  byte local_1038 [4096];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_012372f1;
  local_10 = ExceptionList;
  uVar3 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = uVar3;
  memset(local_1038,0,0x1000);
  local_1058 = 0;
  local_103c = 1;
  FUN_0104dd40(uVar3);
  local_8 = CONCAT31(local_8._1_3_,1);
  local_103f = '\0';
  local_1088 = *param_2;
  if (local_1088 == 1) {
    uVar3 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
    local_1038[2] = (byte)uVar3;
    uVar3 = QVariant::toUInt((QVariant *)&stack0x00000010,(bool *)0x0);
    local_1038[3] = (byte)(uVar3 >> 8);
  }
  else if (local_1088 == 2) {
    local_1038[2] = 0xfe;
    local_1038[3] = 0xff;
  }
  else if (local_1088 == 3) {
    local_1038[2] = 0xff;
    local_1038[3] = 0xff;
  }
  FUN_010f2c50(local_10b4,param_3);
  for (; (local_10a8 != 0 && (local_10b0 != local_10ac)); local_10b0 = local_10b0 + 0x14) {
    FUN_00fe0d60(local_10b0);
    while (local_10a8 != 0) {
      local_10cc = local_1048;
      if (local_107c == 0) {
        local_1048 = 0;
        if (local_1078 == '\0') {
          if (local_103f == '\0') {
            local_10a4 = 3;
          }
          else {
            local_10a4 = 6;
          }
          local_103c = local_103c + local_10a4;
          local_1038[local_103c] = 1;
          local_10b8 = local_103c + 1;
          if (0xfff < local_10b8) {
            ___report_rangecheckfailure();
          }
          local_1038[local_10b8] = 0;
          local_1038[local_103c + 2] = (byte)local_1074;
          *(char *)(local_1044 + 0x18b) = local_1078;
        }
        else {
          if (local_103f == '\0') {
            local_10bc = 3;
          }
          else {
            local_10bc = 6;
          }
          local_103c = local_103c + local_10bc;
          local_1038[local_103c + 2] = (byte)local_1074;
          *(char *)(local_1044 + 0x18b) = local_1078;
        }
      }
      else if (local_107c == 1) {
        local_1048 = 1;
        if (local_1078 == '\0') {
          if (local_103f == '\0') {
            local_1090 = 3;
          }
          else {
            local_1090 = 6;
          }
          local_103c = local_103c + local_1090;
          local_1038[local_103c] = 1;
          local_1094 = local_103c + 1;
          if (0xfff < local_1094) {
            ___report_rangecheckfailure();
          }
          local_1038[local_1094] = 0;
          if (local_1074 == 1) {
            local_1038[local_103c + 2] = 0xf0;
          }
          else if (local_1074 == 2) {
            local_1038[local_103c + 2] = 0xf2;
          }
          else if (local_1074 == 3) {
            local_1038[local_103c + 2] = 0xf1;
          }
          else if (local_1074 == 4) {
            local_1038[local_103c + 2] = 0xf4;
          }
          else if (local_1074 == 5) {
            local_1038[local_103c + 2] = 0xf3;
          }
          *(char *)(local_1044 + 0x18b) = local_1078;
        }
        else {
          if (local_103f == '\0') {
            local_1098 = 3;
          }
          else {
            local_1098 = 6;
          }
          local_103c = local_103c + local_1098;
          if (local_1074 == 1) {
            local_1038[local_103c + 2] = 0xf0;
          }
          else if (local_1074 == 2) {
            local_1038[local_103c + 2] = 0xf2;
          }
          else if (local_1074 == 3) {
            local_1038[local_103c + 2] = 0xf1;
          }
          else if (local_1074 == 4) {
            local_1038[local_103c + 2] = 0xf4;
          }
          else if (local_1074 == 5) {
            local_1038[local_103c + 2] = 0xf3;
          }
          *(char *)(local_1044 + 0x18b) = local_1078;
        }
      }
      else if (local_107c == 2) {
        local_1058 = local_1074;
        if (0x7fff < local_1074) {
          local_1058 = 30000;
        }
        local_1048 = 2;
        if (local_103c == 1) {
          if (param_1 == '\0') {
            local_105c = local_1058 << 1;
            local_103c = 4;
            local_1038[4] = (undefined1)local_105c;
            local_1038[5] = (byte)((uint)local_105c >> 8);
          }
        }
        else {
          if (param_1 != '\0') {
            local_1058 = 5;
          }
          if ((char)local_1044[0x18b] == '\0') {
            local_1060 = local_1058 << 1 | 1;
            local_1038[local_103c] = (byte)local_1060;
            local_1038[local_103c + 1] = (byte)((uint)(local_1058 << 1) >> 8);
          }
          else {
            local_1064 = local_1058 << 1;
            local_1038[local_103c] = (byte)local_1064;
            local_1038[local_103c + 1] = (byte)((uint)local_1064 >> 8);
          }
        }
      }
      else if ((local_107c == 3) && ((local_1074 != 0 || (local_1070 != 0)))) {
        local_1048 = 3;
        if (local_103f == '\0') {
          local_109c = 3;
        }
        else {
          local_109c = 6;
        }
        local_103c = local_103c + local_109c;
        local_1038[local_103c + 2] = 0xf7;
        local_104c = ~(byte)local_1070 + 1;
        local_104a = (byte)(~local_1070 + 1 >> 8) & 0xf;
        bVar1 = (byte)((uint)local_1074 >> 8);
        local_1049 = bVar1 & 0xf;
        local_104b = bVar1 * '\x10' + local_104a;
        local_1038[local_103c + 3] = local_104b;
        local_1038[local_103c + 4] = (byte)local_1074;
        local_1038[local_103c + 5] = local_104c;
        local_103f = '\x01';
        local_1051 = (byte)local_1074;
      }
      local_10a8 = 0;
    }
    FUN_00fe1650();
    local_10a8 = local_10a8 ^ 1;
  }
  FUN_010f3850();
  if (local_1048 == 3) {
    local_1068 = 3;
    local_1038[local_103c] = 3;
    local_1038[local_103c + 1] = 0;
    local_103c = local_103c + 3;
  }
  else if ((local_1048 == 2) && (local_10cc == 3)) {
    local_103c = local_103c + 3;
  }
  local_103c = local_103c + 3;
  local_103e = (byte)local_103c;
  local_1038[1] = (byte)((uint)local_103c >> 8);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_103d = 0x18;
  if (*in_stack_00000020 < 0xb) {
    local_1080 = *in_stack_00000020 * 0x1000 + 0x1000;
  }
  else {
    local_1080 = (*in_stack_00000020 + -1000) * 0x1000 + 0x10000;
  }
  local_1084 = local_1038;
  local_10a0 = 1;
  if (0x18 < local_103c) {
    local_10a0 = local_103c / 0x18 + 1;
  }
  local_1038[0] = local_103e;
  for (local_108c = 1; local_108c < local_10a0; local_108c = local_108c + 1) {
    local_104d = 0xa5;
    FUN_011825d0(&local_38,&local_104d,&local_103d,local_1080);
    memcpy((void *)((int)&local_34 + 3),local_1084,(uint)local_103d);
    local_104e = 0xba;
    local_10e4 = 0x20;
    cVar2 = (**(code **)(*local_1044 + 0x14c))(&local_38,&local_10e4,&local_104e);
    if (cVar2 == '\0') {
      pcVar6 = "setMacro error";
      pQVar5 = local_10c0;
      pQVar4 = (QMessageLogger *)
               QMessageLogger::QMessageLogger(local_1118,(char *)0x0,0,(char *)0x0);
      local_10ec = (QDebug *)QMessageLogger::debug(pQVar4);
      local_8._0_1_ = 2;
      local_10e8 = local_10ec;
      QDebug::operator<<(local_10ec,(char *)pQVar5);
      local_8._0_1_ = 1;
      QDebug::~QDebug(local_10c0);
      local_10c4 = 0xffffffff;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00fe1650(pcVar6);
      local_8 = 0xffffffff;
      QVariant::~QVariant((QVariant *)&stack0x00000010);
      goto LAB_0117b53d;
    }
    memset(&local_38,0,0x21);
    local_103e = local_103e - local_103d;
    local_1084 = local_1084 + local_103d;
    local_1080 = (uint)local_103d + local_1080;
    Sleep(10);
  }
  if (local_103e == 0) {
    local_10c8 = 1;
    local_8 = local_8 & 0xffffff00;
    FUN_00fe1650();
    local_8 = 0xffffffff;
    QVariant::~QVariant((QVariant *)&stack0x00000010);
  }
  else {
    if (local_103e < local_103d) {
      local_104f = 0xa5;
      FUN_011825d0(&local_38,&local_104f,&local_103e,local_1080);
      memcpy((void *)((int)&local_34 + 3),local_1084,(uint)local_103e);
      local_1050 = 0xba;
      local_10f0 = 0x20;
      cVar2 = (**(code **)(*local_1044 + 0x14c))(&local_38,&local_10f0,&local_1050);
      if (cVar2 == '\0') {
        pcVar6 = "setMacro error";
        pQVar5 = local_10d8;
        pQVar4 = (QMessageLogger *)
                 QMessageLogger::QMessageLogger(local_112c,(char *)0x0,0,(char *)0x0);
        local_10d4 = (QDebug *)QMessageLogger::debug(pQVar4);
        local_8._0_1_ = 3;
        local_10d0 = local_10d4;
        QDebug::operator<<(local_10d4,(char *)pQVar5);
        local_8._0_1_ = 1;
        QDebug::~QDebug(local_10d8);
        local_10dc = 0xffffffff;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00fe1650(pcVar6);
        local_8 = 0xffffffff;
        QVariant::~QVariant((QVariant *)&stack0x00000010);
        goto LAB_0117b53d;
      }
    }
    Sleep(local_1044[0x70]);
    local_10e0 = 1;
    local_8 = local_8 & 0xffffff00;
    FUN_00fe1650();
    local_8 = 0xffffffff;
    QVariant::~QVariant((QVariant *)&stack0x00000010);
  }
LAB_0117b53d:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x117a8e0 ===== */

undefined4 FUN_0117a8e0(void)

{
  return 0xffffffff;
}


/* ===== 0x117b560 ===== */

/* WARNING: Removing unreachable block (ram,0x0117b6dd) */
/* WARNING: Removing unreachable block (ram,0x0117b760) */

void FUN_0117b560(undefined4 *param_1)

{
  char cVar1;
  QMessageLogger *this;
  QDebug *pQVar2;
  QMessageLogger local_ec [20];
  QDebug local_d8 [4];
  QDebug *local_d4;
  QDebug *local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  int *local_c0;
  undefined1 local_bc;
  undefined1 local_bb;
  undefined1 local_ba;
  undefined1 local_b9;
  undefined1 local_b8 [7];
  char cStack_b1;
  char cStack_b0;
  char cStack_af;
  char cStack_ae;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01237325;
  local_10 = ExceptionList;
  local_14 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  memset(local_b8,0,0x80);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  cVar1 = FUN_01182530(&local_38,0x884);
  if (cVar1 == '\0') {
    pQVar2 = local_d8;
    this = (QMessageLogger *)QMessageLogger::QMessageLogger(local_ec,(char *)0x0,0,(char *)0x0);
    local_d4 = (QDebug *)QMessageLogger::debug(this);
    local_8 = 0;
    local_d0 = local_d4;
    QDebug::operator<<(local_d4,(char *)pQVar2);
    local_8 = 0xffffffff;
    QDebug::~QDebug(local_d8);
  }
  else {
    local_b9 = 4;
    local_ba = 0xa5;
    FUN_011825d0(local_b8,&local_ba,&local_b9,0x884);
    cStack_b1 = (char)*param_1 + '\x01';
    cStack_b0 = local_34._1_1_;
    cStack_af = local_34._2_1_;
    cStack_ae = local_34._3_1_;
    if (((local_34._1_1_ == '\0') && (local_34._2_1_ == '\0')) && (local_34._3_1_ == '\0')) {
      cStack_b0 = '\x01';
      local_c4 = 9;
      cStack_af = '\0';
      cStack_ae = '\x03';
    }
    if (((local_34._1_1_ == '\x01') && (local_34._2_1_ == '\0')) && (local_34._3_1_ == '\0')) {
      cStack_b0 = '\x01';
      local_c8 = 9;
      cStack_af = '\0';
      cStack_ae = '\x03';
    }
    cVar1 = (**(code **)(*local_c0 + 0x148))();
    if (cVar1 != '\0') {
      local_bb = 0xba;
      local_cc = 0x20;
      local_bc = (**(code **)(*local_c0 + 0x14c))(local_b8,&local_cc,&local_bb);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x117b870 ===== */

/* WARNING: Removing unreachable block (ram,0x0117ba01) */

void FUN_0117b870(int *param_1)

{
  char cVar1;
  QMessageLogger *pQVar2;
  QDebug *pQVar3;
  QMessageLogger local_108 [20];
  QMessageLogger local_f4 [20];
  QDebug local_e0 [4];
  QDebug *local_dc;
  QDebug *local_d8;
  undefined4 local_d4;
  QDebug local_d0 [4];
  QDebug *local_cc;
  QDebug *local_c8;
  undefined4 local_c4;
  int *local_c0;
  undefined1 local_bc;
  undefined1 local_bb;
  undefined1 local_ba;
  undefined1 local_b9;
  undefined1 local_b8 [7];
  undefined1 uStack_b1;
  undefined1 uStack_b0;
  undefined1 uStack_af;
  undefined1 uStack_ae;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01237365;
  local_10 = ExceptionList;
  local_14 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*param_1 < 0x65) || (4 < *param_1)) {
    memset(local_b8,0,0x80);
    local_b9 = 4;
    local_ba = 0xa5;
    FUN_011825d0(local_b8,&local_ba,&local_b9,0x89c);
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    cVar1 = FUN_01182530(&local_38,0x89c);
    if (cVar1 == '\0') {
      pQVar3 = local_e0;
      pQVar2 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_108,(char *)0x0,0,(char *)0x0)
      ;
      local_dc = (QDebug *)QMessageLogger::debug(pQVar2);
      local_8 = 1;
      local_d8 = local_dc;
      QDebug::operator<<(local_dc,(char *)pQVar3);
      local_8 = 0xffffffff;
      QDebug::~QDebug(local_e0);
    }
    else {
      uStack_b1 = (undefined1)*param_1;
      uStack_af = local_34._2_1_;
      uStack_b0 = local_34._1_1_;
      local_c4 = 10;
      uStack_ae = 0;
      cVar1 = (**(code **)(*local_c0 + 0x148))();
      if (cVar1 != '\0') {
        local_bb = 0xba;
        local_d4 = 0x20;
        local_bc = (**(code **)(*local_c0 + 0x14c))(local_b8,&local_d4,&local_bb);
      }
    }
  }
  else {
    pQVar3 = local_d0;
    pQVar2 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_f4,(char *)0x0,0,(char *)0x0);
    local_cc = (QDebug *)QMessageLogger::debug(pQVar2);
    local_8 = 0;
    local_c8 = local_cc;
    QDebug::operator<<(local_cc,(char *)pQVar3);
    local_8 = 0xffffffff;
    QDebug::~QDebug(local_d0);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x117bd30 ===== */

void FUN_0117bd30(int *param_1)

{
  char cVar1;
  uint uVar2;
  QMessageLogger *pQVar3;
  QDebug *pQVar4;
  QMessageLogger local_10c [20];
  QMessageLogger local_f8 [20];
  QDebug local_e4 [4];
  QDebug *local_e0;
  QDebug *local_dc;
  undefined4 local_d8;
  QDebug local_d4 [4];
  QDebug *local_d0;
  QDebug *local_cc;
  int local_c8;
  int *local_c4;
  undefined1 local_be;
  undefined1 local_bd;
  undefined1 local_bc;
  undefined1 local_bb;
  undefined1 local_ba;
  undefined1 local_b9;
  undefined1 local_b8 [7];
  undefined1 uStack_b1;
  undefined1 uStack_b0;
  undefined1 uStack_af;
  undefined1 uStack_ae;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_012373a5;
  local_10 = ExceptionList;
  uVar2 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (*param_1 < 10) {
    local_b9 = (undefined1)*param_1;
    local_ba = 0;
    local_c8 = *param_1;
    switch(local_c8) {
    case 0:
      local_b9 = 0;
      break;
    case 1:
      local_b9 = 1;
      break;
    case 2:
      local_b9 = 2;
      break;
    case 3:
      local_b9 = 3;
      break;
    case 4:
      local_b9 = 5;
      break;
    case 5:
      local_b9 = 7;
      break;
    case 6:
      local_b9 = 8;
      break;
    case 7:
      local_ba = 1;
      local_b9 = 3;
    }
    memset(local_b8,0,0x80);
    local_bb = 4;
    local_bc = 0xa5;
    FUN_011825d0(local_b8,&local_bc,&local_bb,0x8ac);
    uStack_b0 = local_b9;
    uStack_af = local_ba;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    cVar1 = FUN_01182530(&local_38,0x8ac);
    if (cVar1 == '\0') {
      pQVar4 = local_e4;
      pQVar3 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_10c,(char *)0x0,0,(char *)0x0)
      ;
      local_e0 = (QDebug *)QMessageLogger::debug(pQVar3);
      local_8 = 1;
      local_dc = local_e0;
      QDebug::operator<<(local_e0,(char *)pQVar4);
      local_8 = 0xffffffff;
      QDebug::~QDebug(local_e4);
    }
    else {
      uStack_b1 = (undefined1)local_34;
      uStack_b0 = local_b9;
      uStack_af = local_ba;
      uStack_ae = local_34._3_1_;
      cVar1 = (**(code **)(*local_c4 + 0x148))(uVar2);
      if (cVar1 != '\0') {
        local_bd = 0xba;
        local_d8 = 0x20;
        local_be = (**(code **)(*local_c4 + 0x14c))(local_b8,&local_d8,&local_bd);
      }
    }
  }
  else {
    pQVar4 = local_d4;
    pQVar3 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_f8,(char *)0x0,0,(char *)0x0);
    local_d0 = (QDebug *)QMessageLogger::debug(pQVar3);
    local_8 = 0;
    local_cc = local_d0;
    QDebug::operator<<(local_d0,(char *)pQVar4);
    local_8 = 0xffffffff;
    QDebug::~QDebug(local_d4);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x117c070 ===== */

void FUN_0117c070(int *param_1)

{
  char cVar1;
  QString *pQVar2;
  QImage local_1d4 [16];
  undefined1 *local_1c4;
  QImage local_1c0 [16];
  undefined4 local_1b0;
  QString local_1ac [4];
  undefined4 local_1a8;
  undefined4 local_1a4;
  QString local_1a0 [4];
  int *local_19c;
  undefined1 local_197;
  undefined1 local_196;
  undefined1 local_195;
  undefined1 local_194 [384];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_012373fd;
  local_10 = ExceptionList;
  local_14 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  QImage::QImage(local_1c0,0x40,0x30,2);
  local_8 = 0;
  pQVar2 = local_1ac;
  FUN_00fcb520(pQVar2);
  local_1a8 = FUN_011c36f0(pQVar2);
  local_8._0_1_ = 1;
  local_1a4 = local_1a8;
  FUN_00fb89e0(local_1a0,local_1a8);
  local_8._0_1_ = 3;
  QString::~QString(local_1ac);
  QImage::load(local_1c0,local_1a0,(char *)0x0);
  if (*param_1 == 1) {
    local_195 = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    QString::~QString(local_1a0);
    local_8 = 0xffffffff;
    QImage::~QImage(local_1c0);
  }
  else {
    local_1c4 = &stack0xfffffe24;
    FUN_00fb8360(0);
    QImage::convertToFormat(local_1c0,local_1d4,2);
    local_8._0_1_ = 4;
    memset(local_194,0,0x180);
    cVar1 = FUN_0117f050(local_1d4,local_194);
    if (cVar1 != '\0') {
      FUN_0117f450();
      local_1b0 = 8;
      cVar1 = (**(code **)(*local_19c + 0xe8))();
      if (cVar1 != '\0') {
        local_196 = 1;
        local_8._0_1_ = 3;
        QImage::~QImage(local_1d4);
        local_8 = (uint)local_8._1_3_ << 8;
        QString::~QString(local_1a0);
        local_8 = 0xffffffff;
        QImage::~QImage(local_1c0);
        goto LAB_0117c28a;
      }
    }
    local_197 = 0;
    local_8._0_1_ = 3;
    QImage::~QImage(local_1d4);
    local_8 = (uint)local_8._1_3_ << 8;
    QString::~QString(local_1a0);
    local_8 = 0xffffffff;
    QImage::~QImage(local_1c0);
  }
LAB_0117c28a:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x117f860 ===== */

void FUN_0117f860(int *param_1)

{
  uint uVar1;
  QMessageLogger *this;
  QDebug *pQVar2;
  QMessageLogger local_c0 [20];
  undefined4 local_ac;
  QDebug local_a8 [4];
  QDebug *local_a4;
  QDebug *local_a0;
  int *local_9c;
  undefined1 local_98;
  undefined1 local_97;
  undefined1 local_96;
  char local_95;
  undefined1 local_94 [7];
  undefined1 uStack_8d;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0123772e;
  local_10 = ExceptionList;
  uVar1 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  if (*param_1 == 8) {
    memset(local_94,0,0x80);
    local_96 = 4;
    local_97 = 0xa5;
    FUN_011825d0(local_94,&local_97,&local_96,0x8a0);
    uStack_8d = (undefined1)*param_1;
    local_98 = 0xba;
    local_ac = 0x20;
    local_95 = (**(code **)(*local_9c + 0x14c))(local_94,&local_ac,&local_98,uVar1);
    if (local_95 != '\0') {
      *(char *)((int)local_9c + 0x4a3) = (char)*param_1;
    }
  }
  else {
    pQVar2 = local_a8;
    this = (QMessageLogger *)QMessageLogger::QMessageLogger(local_c0,(char *)0x0,0,(char *)0x0);
    local_a4 = (QDebug *)QMessageLogger::debug(this);
    local_8 = 0;
    local_a0 = local_a4;
    QDebug::operator<<(local_a4,(char *)pQVar2);
    local_8 = 0xffffffff;
    QDebug::~QDebug(local_a8);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x117c2b0 ===== */

/* WARNING: Removing unreachable block (ram,0x0117c441) */

void FUN_0117c2b0(int *param_1)

{
  char cVar1;
  QMessageLogger *pQVar2;
  QDebug *pQVar3;
  QMessageLogger local_108 [20];
  QMessageLogger local_f4 [20];
  QDebug local_e0 [4];
  QDebug *local_dc;
  QDebug *local_d8;
  undefined4 local_d4;
  QDebug local_d0 [4];
  QDebug *local_cc;
  QDebug *local_c8;
  undefined4 local_c4;
  int *local_c0;
  undefined1 local_bc;
  undefined1 local_bb;
  undefined1 local_ba;
  undefined1 local_b9;
  undefined1 local_b8 [7];
  undefined1 uStack_b1;
  undefined1 uStack_b0;
  undefined1 uStack_af;
  undefined1 uStack_ae;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0123743d;
  local_10 = ExceptionList;
  local_14 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*param_1 < 4) || (-1 < *param_1)) {
    memset(local_b8,0,0x80);
    local_b9 = 4;
    local_ba = 0xa5;
    FUN_011825d0(local_b8,&local_ba,&local_b9,0x89c);
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    cVar1 = FUN_01182530(&local_38,0x89c);
    if (cVar1 == '\0') {
      pQVar3 = local_e0;
      pQVar2 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_108,(char *)0x0,0,(char *)0x0)
      ;
      local_dc = (QDebug *)QMessageLogger::debug(pQVar2);
      local_8 = 1;
      local_d8 = local_dc;
      QDebug::operator<<(local_dc,(char *)pQVar3);
      local_8 = 0xffffffff;
      QDebug::~QDebug(local_e0);
    }
    else {
      uStack_b0 = (undefined1)*param_1;
      uStack_af = local_34._2_1_;
      uStack_b1 = (undefined1)local_34;
      local_c4 = 10;
      uStack_ae = 0;
      local_bb = 0xba;
      local_d4 = 0x20;
      local_bc = (**(code **)(*local_c0 + 0x14c))(local_b8,&local_d4,&local_bb);
    }
  }
  else {
    pQVar3 = local_d0;
    pQVar2 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_f4,(char *)0x0,0,(char *)0x0);
    local_cc = (QDebug *)QMessageLogger::debug(pQVar2);
    local_8 = 0;
    local_c8 = local_cc;
    QDebug::operator<<(local_cc,(char *)pQVar3);
    local_8 = 0xffffffff;
    QDebug::~QDebug(local_d0);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x117c520 ===== */

/* WARNING: Removing unreachable block (ram,0x0117c682) */
/* WARNING: Removing unreachable block (ram,0x0117c6c5) */

void FUN_0117c520(int *param_1)

{
  char cVar1;
  QMessageLogger *pQVar2;
  QDebug *pQVar3;
  QMessageLogger local_110 [20];
  QMessageLogger local_fc [20];
  QDebug local_e8 [4];
  QDebug *local_e4;
  QDebug *local_e0;
  undefined4 local_dc;
  QDebug local_d8 [4];
  QDebug *local_d4;
  QDebug *local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined1 local_c3;
  undefined1 local_c2;
  undefined1 local_c1;
  int *local_c0;
  char local_b9;
  undefined1 local_b8 [7];
  undefined1 uStack_b1;
  undefined1 uStack_b0;
  undefined1 uStack_af;
  undefined1 uStack_ae;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0123747d;
  local_10 = ExceptionList;
  local_14 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*param_1 < 4) || (-1 < *param_1)) {
    memset(local_b8,0,0x80);
    local_c1 = 4;
    local_c2 = 0xa5;
    FUN_011825d0(local_b8,&local_c2,&local_c1,0x89c);
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    cVar1 = FUN_01182530(&local_38,0x89c);
    if (cVar1 == '\0') {
      pQVar3 = local_e8;
      pQVar2 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_110,(char *)0x0,0,(char *)0x0)
      ;
      local_e4 = (QDebug *)QMessageLogger::debug(pQVar2);
      local_8 = 1;
      local_e0 = local_e4;
      QDebug::operator<<(local_e4,(char *)pQVar3);
      local_8 = 0xffffffff;
      QDebug::~QDebug(local_e8);
    }
    else {
      uStack_b1 = (undefined1)local_34;
      uStack_b0 = 0;
      uStack_af = (undefined1)*param_1;
      local_c8 = 8;
      local_cc = 10;
      uStack_ae = 0;
      local_c3 = 0xba;
      local_dc = 0x20;
      local_b9 = (**(code **)(*local_c0 + 0x14c))(local_b8,&local_dc,&local_c3);
      if (local_b9 != '\0') {
        local_c0[0x76] = *param_1;
        *(char *)((int)local_c0 + 0x4a1) = (char)local_c0[0x76];
      }
      Sleep(local_c0[0x70]);
    }
  }
  else {
    pQVar3 = local_d8;
    pQVar2 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_fc,(char *)0x0,0,(char *)0x0);
    local_d4 = (QDebug *)QMessageLogger::debug(pQVar2);
    local_8 = 0;
    local_d0 = local_d4;
    QDebug::operator<<(local_d4,(char *)pQVar3);
    local_8 = 0xffffffff;
    QDebug::~QDebug(local_d8);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x117c7f0 ===== */

void FUN_0117c7f0(void)

{
  undefined4 local_94;
  int *local_90;
  undefined1 local_8c;
  undefined1 local_8b;
  undefined1 local_8a;
  undefined1 local_89;
  undefined1 local_88 [3];
  undefined1 uStack_85;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  memset(local_88,0,0x80);
  local_89 = 0x52;
  local_8a = 0xad;
  FUN_011825d0(local_88,&local_8a,&local_89,0);
  uStack_85 = 0x3d;
  local_8b = 0xba;
  local_94 = 0x20;
  local_8c = (**(code **)(*local_90 + 0x14c))(local_88,&local_94,&local_8b);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x11246c0 ===== */

void FUN_011246c0(char param_1)

{
  char cVar1;
  undefined4 local_bc;
  uint local_b8;
  int *local_b4;
  undefined1 local_b0;
  undefined1 local_af;
  undefined1 local_ae;
  undefined1 local_ad;
  undefined1 local_ac [7];
  undefined1 uStack_a5;
  undefined1 uStack_a4;
  undefined1 uStack_a3;
  undefined1 uStack_a2;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  memset(local_ac,0,0x80);
  local_ad = 4;
  local_ae = 0xa5;
  FUN_011825d0(local_ac,&local_ae,&local_ad,0x8ac);
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  cVar1 = FUN_01182530(&local_2c,0x8ac);
  if (cVar1 != '\0') {
    uStack_a5 = (undefined1)local_28;
    uStack_a4 = local_28._1_1_;
    uStack_a3 = local_28._2_1_;
    uStack_a2 = param_1 != '\0';
    local_b8 = (uint)(byte)uStack_a2;
    cVar1 = (**(code **)(*local_b4 + 0x148))();
    if (cVar1 != '\0') {
      local_af = 0xba;
      local_bc = 0x20;
      local_b0 = (**(code **)(*local_b4 + 0x14c))(local_ac,&local_bc,&local_af);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x1124a20 ===== */

void FUN_01124a20(int *param_1)

{
  char cVar1;
  undefined4 local_bc;
  int local_b8;
  int *local_b4;
  undefined1 local_b0;
  undefined1 local_af;
  undefined1 local_ae;
  undefined1 local_ad;
  undefined1 local_ac [7];
  undefined1 uStack_a5;
  undefined1 uStack_a4;
  undefined1 uStack_a3;
  undefined1 uStack_a2;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  local_b8 = *param_1 + 1;
  memset(local_ac,0,0x80);
  local_ad = 4;
  local_ae = 0xa5;
  FUN_011825d0(local_ac,&local_ae,&local_ad,0x884);
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  cVar1 = FUN_01182530(&local_2c,0x884);
  if (cVar1 != '\0') {
    uStack_a5 = (undefined1)local_28;
    uStack_a4 = (undefined1)local_b8;
    uStack_a3 = local_28._2_1_;
    uStack_a2 = local_28._3_1_;
    local_af = 0xba;
    local_bc = 0x20;
    local_b0 = (**(code **)(*local_b4 + 0x14c))(local_ac,&local_bc,&local_af);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x117cda0 ===== */

void FUN_0117cda0(void)

{
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  int *local_a8;
  int local_a4;
  int local_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a;
  undefined1 local_99;
  undefined1 local_98;
  undefined1 local_97;
  undefined1 local_96;
  undefined1 local_95;
  undefined1 local_94 [7];
  undefined1 uStack_8d;
  undefined1 uStack_8c;
  undefined1 uStack_8b;
  undefined1 uStack_8a;
  undefined1 uStack_89;
  undefined1 uStack_88;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_012374ad;
  local_10 = ExceptionList;
  local_14 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_b4 = 0;
  local_b8 = 0;
  local_e8 = FUN_01000270(&local_b8,&local_b4);
  local_bc = 0;
  local_c0 = 1;
  local_ec = FUN_01000270(&local_c0,&local_bc);
  local_100 = 0;
  local_c4 = 2;
  local_f0 = FUN_01000270(&local_c4,&local_100);
  local_c8 = 0;
  local_cc = 3;
  local_a0 = FUN_01000270(&local_cc,&local_c8);
  local_d0 = 0;
  local_d4 = 4;
  local_a4 = FUN_01000270(&local_d4,&local_d0);
  local_d8 = 0;
  local_dc = 5;
  local_f8 = FUN_01000270(&local_dc,&local_d8);
  local_e0 = 0;
  local_e4 = 6;
  local_f4 = FUN_01000270(&local_e4,&local_e0);
  local_96 = 0;
  local_95 = 0;
  local_ac = local_e8;
  switch(local_e8) {
  case 0:
    local_96 = 1;
    break;
  case 1:
    local_96 = 2;
    break;
  case 2:
    local_96 = 4;
    break;
  case 3:
    local_96 = 8;
    break;
  case 4:
    local_96 = 0x10;
    break;
  case 5:
    local_96 = 0x18;
    break;
  case 6:
    local_96 = 0x20;
  }
  local_b0 = local_ec;
  switch(local_ec) {
  case 0:
    local_95 = 1;
    break;
  case 1:
    local_95 = 2;
    break;
  case 2:
    local_95 = 4;
    break;
  case 3:
    local_95 = 8;
    break;
  case 4:
    local_95 = 0x10;
    break;
  case 5:
    local_95 = 0x18;
    break;
  case 6:
    local_95 = 0x20;
  }
  if ((local_a0 == 1) && (local_a4 == 1)) {
    local_97 = 0;
  }
  else if ((local_a0 == 1) && (local_a4 == 0)) {
    local_97 = 2;
  }
  else if ((local_a0 == 0) && (local_a4 == 1)) {
    local_97 = 1;
  }
  else {
    local_97 = 3;
  }
  memset(local_94,0,0x80);
  local_98 = 8;
  local_99 = 0xa5;
  FUN_011825d0(local_94,&local_99,&local_98,0x8c0);
  uStack_8d = local_96;
  uStack_8c = local_95;
  uStack_8b = (undefined1)local_f0;
  uStack_8a = local_97;
  uStack_89 = (undefined1)local_f4;
  uStack_88 = (undefined1)local_f8;
  local_9a = 0xba;
  local_fc = 0x20;
  local_9c = (**(code **)(*local_a8 + 0x14c))(local_94,&local_fc,&local_9a);
  local_8 = 0xffffffff;
  local_9b = local_9c;
  FUN_00fc1420();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x117d1d0 ===== */

void FUN_0117d1d0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined4 local_e4;
  undefined4 local_e0;
  uint local_dc;
  undefined4 local_d8;
  uint local_d4;
  undefined4 local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  undefined1 local_b8 [5];
  char local_b3;
  undefined1 local_b2;
  undefined1 local_b1;
  undefined1 local_b0;
  undefined1 local_af;
  undefined1 local_ae;
  undefined1 local_ad;
  undefined1 local_ac;
  undefined1 local_ab;
  undefined1 local_aa;
  undefined1 local_a9;
  int local_a8;
  int *local_a0;
  char local_99;
  int local_98;
  char local_94 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_012374eb;
  local_10 = ExceptionList;
  uVar2 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  memset(local_94,0,0x80);
  local_a9 = 0x10;
  local_aa = 0xa5;
  cVar1 = FUN_011825d0(local_94,&local_aa,&local_a9,0x888);
  if (cVar1 != '\0') {
    puVar7 = local_b8;
    FUN_00fb9e10(puVar7,uVar2);
    FUN_011c4290();
    FUN_01070b20();
    FUN_0101f640(puVar7);
    local_8 = 0;
    local_98 = 7;
    local_a8 = 0;
    FUN_00fb8560();
    local_8 = CONCAT31(local_8._1_3_,1);
    local_bc = 0;
    while (iVar3 = FUN_00fc0ae0(), local_bc < iVar3) {
      pcVar4 = (char *)FUN_01026ce0(local_bc);
      if (*pcVar4 == '\0') {
        uVar5 = FUN_010136e0(local_bc);
        FUN_00fe75e0(uVar5);
        local_a8 = local_a8 + 1;
      }
      else {
        puVar6 = (undefined4 *)FUN_010136e0(local_bc);
        local_d0 = *puVar6;
        local_94[local_98] = (char)local_d0;
        local_94[local_98 + 1] = (char)((uint)local_d0 >> 8);
        local_98 = local_98 + 2;
      }
      local_bc = local_bc + 1;
    }
    for (local_c4 = 0; local_c4 < local_a8; local_c4 = local_c4 + 1) {
      puVar6 = (undefined4 *)FUN_00fe8400(local_c4);
      local_94[local_98] = (char)*puVar6;
      local_98 = local_98 + 1;
      puVar6 = (undefined4 *)FUN_00fe8400(local_c4);
      local_94[local_98] = (char)((uint)*puVar6 >> 8);
      local_98 = local_98 + 1;
    }
    local_94[local_98] = '\x06' - (char)local_a8;
    local_d4 = local_98 + 1;
    local_98 = local_98 + 2;
    if (0x7f < local_d4) {
      ___report_rangecheckfailure();
    }
    local_94[local_d4] = '\0';
    local_cc = (**(code **)(*local_a0 + 0x38))();
    if (6 - local_a8 < local_cc) {
      local_cc = 6 - local_a8;
      cVar1 = (**(code **)(*local_a0 + 0xac))(&local_cc);
      if (cVar1 == '\0') {
        local_ab = 0;
        local_8 = local_8 & 0xffffff00;
        FUN_00fb86c0();
        local_8 = 0xffffffff;
        FUN_01022fa0();
        goto LAB_0117d8e7;
      }
    }
    cVar1 = (**(code **)(*local_a0 + 0x148))();
    if (cVar1 == '\0') {
      local_ac = 0;
      local_8 = local_8 & 0xffffff00;
      FUN_00fb86c0();
      local_8 = 0xffffffff;
      FUN_01022fa0();
    }
    else {
      local_ad = 0xba;
      local_e0 = 0x20;
      local_99 = (**(code **)(*local_a0 + 0x14c))(local_94,&local_e0,&local_ad);
      if (local_99 == '\0') {
        local_ae = 0;
        local_8 = local_8 & 0xffffff00;
        FUN_00fb86c0();
        local_8 = 0xffffffff;
        FUN_01022fa0();
      }
      else {
        memset(local_94,0,0x80);
        local_af = 0x10;
        local_b0 = 0xa5;
        cVar1 = FUN_011825d0(local_94,&local_b0,&local_af,0x8c8);
        if (cVar1 == '\0') {
          local_b1 = 0;
          local_8 = local_8 & 0xffffff00;
          FUN_00fb86c0();
          local_8 = 0xffffffff;
          FUN_01022fa0();
        }
        else {
          local_98 = 7;
          local_a8 = 0;
          FUN_00fe7750();
          local_c0 = 0;
          while (iVar3 = FUN_00fc0ae0(), local_c0 < iVar3) {
            pcVar4 = (char *)FUN_01026ce0(local_c0);
            if (*pcVar4 == '\0') {
              iVar3 = FUN_010136e0(local_c0);
              FUN_00fe75e0(iVar3 + 4);
              local_a8 = local_a8 + 1;
            }
            else {
              iVar3 = FUN_010136e0(local_c0);
              local_d8 = *(undefined4 *)(iVar3 + 4);
              local_94[local_98] = (char)local_d8;
              local_94[local_98 + 1] = (char)((uint)local_d8 >> 8);
              local_98 = local_98 + 2;
            }
            local_c0 = local_c0 + 1;
          }
          for (local_c8 = 0; local_c8 < local_a8; local_c8 = local_c8 + 1) {
            puVar6 = (undefined4 *)FUN_00fe8400(local_c8);
            local_94[local_98] = (char)*puVar6;
            local_98 = local_98 + 1;
            puVar6 = (undefined4 *)FUN_00fe8400(local_c8);
            local_94[local_98] = (char)((uint)*puVar6 >> 8);
            local_98 = local_98 + 1;
          }
          local_94[local_98] = '\x06' - (char)local_a8;
          local_dc = local_98 + 1;
          local_98 = local_98 + 2;
          if (0x7f < local_dc) {
            ___report_rangecheckfailure();
          }
          local_94[local_dc] = '\0';
          local_b2 = 0xba;
          local_e4 = 0x20;
          local_b3 = (**(code **)(*local_a0 + 0x14c))(local_94,&local_e4,&local_b2);
          local_8 = local_8 & 0xffffff00;
          local_99 = local_b3;
          FUN_00fb86c0();
          local_8 = 0xffffffff;
          FUN_01022fa0();
        }
      }
    }
  }
LAB_0117d8e7:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x112b580 ===== */

void FUN_0112b580(int *param_1,int *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18 [4];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0123186a;
  local_10 = ExceptionList;
  uVar1 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_40 = 0;
  local_3c = 2;
  local_38 = 1;
  local_34 = 7;
  local_30 = 8;
  local_2c = 0xd;
  local_28 = 0xb;
  local_24 = 0xc;
  local_20 = 5;
  local_1c = 6;
  local_14 = uVar1;
  puVar2 = (undefined4 *)FUN_00fc13f0(&local_40,local_18);
  FUN_00fc12b0(*puVar2,puVar2[1]);
  local_8 = 0;
  local_48 = 0;
  while( true ) {
    iVar3 = FUN_00fc0ae0(uVar1);
    if (iVar3 <= local_48) break;
    piVar4 = (int *)FUN_00fe8400(local_48);
    if (*piVar4 == *param_1) {
      *param_2 = local_48;
    }
    local_48 = local_48 + 1;
  }
  local_8 = 0xffffffff;
  FUN_00fb86c0();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x117da20 ===== */

undefined1 FUN_0117da20(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 *puVar4;
  int local_24;
  undefined1 local_1c [4];
  int local_18;
  undefined1 local_13;
  undefined1 local_12;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01237548;
  local_10 = ExceptionList;
  uVar1 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar4 = local_1c;
  FUN_00fb9e10(puVar4,uVar1);
  FUN_011c4290();
  FUN_01070b60();
  FUN_01040b60(puVar4);
  local_8 = 0;
  local_24 = 0;
  local_11 = '\0';
  local_18 = 0;
  while (iVar2 = FUN_00ff83e0(), local_18 < iVar2) {
    FUN_00ffc860(local_18);
    uVar3 = FUN_0104d480();
    if ((((*(char *)(in_ECX + 0x4a1) == '\0') || (local_18 != 0)) ||
        (*(int *)(in_ECX + 0x1e8) <= *(int *)(in_ECX + 0x1e0))) &&
       (iVar2 = FUN_01033420(uVar1,uVar3), iVar2 == 9)) {
      local_24 = local_24 + 1;
      iVar2 = FUN_01033710();
      if (*param_1 == iVar2) {
        local_11 = '\x01';
      }
    }
    local_18 = local_18 + 1;
  }
  if ((local_24 < 2) && (local_11 != '\0')) {
    local_12 = 0;
    local_8 = 0xffffffff;
    FUN_00ff63a0();
  }
  else {
    local_13 = 1;
    local_8 = 0xffffffff;
    FUN_00ff63a0();
    local_12 = local_13;
  }
  ExceptionList = local_10;
  return local_12;
}


/* ===== 0x117db60 ===== */

undefined1 FUN_0117db60(void)

{
  char cVar1;
  bool bVar2;
  QMessageLogger *this;
  int iVar3;
  undefined4 *puVar4;
  QDebug *pQVar5;
  char *pcVar6;
  undefined4 uVar7;
  int *piVar8;
  QMessageLogger local_78 [20];
  undefined1 local_64 [4];
  undefined1 local_60;
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  undefined1 local_48 [4];
  undefined4 local_44;
  undefined1 local_40 [8];
  QDebug local_38 [4];
  QDebug *local_34;
  QDebug *local_30;
  undefined1 local_24 [12];
  int local_18;
  undefined1 local_12;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01237594;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00fc1060(DAT_037b6510 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  FUN_00fc1060();
  local_8._0_1_ = 1;
  FUN_00fc1060();
  local_8._0_1_ = 2;
  FUN_00fb8560();
  local_8._0_1_ = 3;
  cVar1 = FUN_00fe4b70();
  if (cVar1 == '\0') {
    local_18 = FUN_0100ab70();
    while (local_18 = local_18 + -1, -1 < local_18) {
      iVar3 = FUN_01069940(local_18);
      if (*(char *)(iVar3 + 4) == '\x01') {
        iVar3 = FUN_01069940(local_18);
        cVar1 = FUN_010168b0(iVar3 + 0x10);
        if (cVar1 == '\0') {
          piVar8 = &local_18;
          iVar3 = FUN_01069940(local_18);
          FUN_00fff190(local_48,iVar3 + 0x10,piVar8);
        }
        else {
          piVar8 = &local_18;
          iVar3 = FUN_01069940(local_18);
          FUN_00fff190(local_40,iVar3 + 0x10,piVar8);
          uVar7 = 0;
          iVar3 = FUN_01069940(local_18);
          local_44 = FUN_01069dd0(iVar3 + 0x10,uVar7);
          uVar7 = 0;
          iVar3 = FUN_01069940(local_18);
          uVar7 = FUN_01069dd0(iVar3 + 0x10,uVar7);
          FUN_0106a3b0(uVar7);
        }
      }
      else {
        iVar3 = FUN_01069940(local_18);
        cVar1 = FUN_010529f0(iVar3 + 0x10);
        if (cVar1 == '\0') {
          iVar3 = FUN_01069940(local_18);
          cVar1 = FUN_010168b0(iVar3 + 0x10);
          if (cVar1 == '\0') {
            pcVar6 = "";
            iVar3 = FUN_01069940(local_18);
            bVar2 = QString::operator!=((QString *)(iVar3 + 0x10),pcVar6);
            if (bVar2) {
              uVar7 = FUN_01069940(local_18);
              FUN_00fe0d60(uVar7);
              local_8._0_1_ = 5;
              local_60 = 1;
              FUN_01052760(local_64);
              iVar3 = FUN_01069940(local_18);
              FUN_0100a320(iVar3 + 0x10);
              local_8._0_1_ = 3;
              FUN_00fe1650();
            }
          }
        }
        iVar3 = FUN_01069940(local_18);
        cVar1 = FUN_010529f0(iVar3 + 0x10);
        if (cVar1 != '\0') {
          iVar3 = FUN_01069940(local_18);
          cVar1 = FUN_010168b0(iVar3 + 0x10);
          if (cVar1 == '\0') {
            iVar3 = FUN_01069940(local_18);
            FUN_0106a310(iVar3 + 0x10);
            iVar3 = FUN_01069940(local_18);
            FUN_0100a320(iVar3 + 0x10);
          }
        }
      }
    }
    cVar1 = FUN_01016b00();
    if (cVar1 == '\0') {
      FUN_010699e0(local_24);
      while( true ) {
        uVar7 = FUN_01069a70(local_50);
        cVar1 = FUN_00fb8890(uVar7);
        if (cVar1 == '\0') break;
        puVar4 = (undefined4 *)FUN_00fc02d0();
        FUN_0106a3f0(*puVar4);
        FUN_00fc1650(local_4c,0);
      }
    }
    local_12 = 1;
    local_8._0_1_ = 2;
    FUN_00fe13d0();
    local_8._0_1_ = 1;
    FUN_00fe1210();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00fe1210();
    local_8 = 0xffffffff;
    FUN_00fe1210();
    local_11 = local_12;
  }
  else {
    pcVar6 = "[Error] macro is empty!!";
    pQVar5 = local_38;
    this = (QMessageLogger *)QMessageLogger::QMessageLogger(local_78,(char *)0x0,0,(char *)0x0);
    local_34 = (QDebug *)QMessageLogger::debug(this);
    local_8._0_1_ = 4;
    local_30 = local_34;
    QDebug::operator<<(local_34,(char *)pQVar5);
    local_8._0_1_ = 3;
    QDebug::~QDebug(local_38);
    local_11 = 0;
    local_8._0_1_ = 2;
    FUN_00fe13d0(pcVar6);
    local_8._0_1_ = 1;
    FUN_00fe1210();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00fe1210();
    local_8 = 0xffffffff;
    FUN_00fe1210();
  }
  ExceptionList = local_10;
  return local_11;
}


/* ===== 0x117c8c0 ===== */

undefined4 FUN_0117c8c0(void)

{
  return 0;
}


/* ===== 0x112c2a0 ===== */

undefined4 FUN_0112c2a0(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  QMessageLogger *pQVar4;
  QDebug *pQVar5;
  int *in_ECX;
  char *pcVar6;
  QMessageLogger local_68 [20];
  QMessageLogger local_54 [20];
  undefined8 local_40;
  QDebug local_38 [4];
  QDebug *local_34;
  QDebug *local_30;
  QDebug local_2c [4];
  QDebug *local_28;
  QDebug *local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01231a59;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = in_ECX;
  if (in_ECX[0x6e] < 0x2000) {
    local_40 = (**(code **)(*in_ECX + 0x98))(DAT_037b6510 ^ (uint)&stack0xfffffffc);
    if (local_40 == -1) {
      ExceptionList = local_10;
      return 0;
    }
    FUN_01202720(local_40);
  }
  iVar2 = (**(code **)(*local_14 + 0x144))();
  if (iVar2 == -1) {
    cVar1 = (**(code **)(*local_14 + 0x15c))();
    if (cVar1 == '\0') {
      ExceptionList = local_10;
      return 0;
    }
    iVar2 = (**(code **)(*local_14 + 0x144))();
    if (iVar2 == -1) {
      ExceptionList = local_10;
      return 0;
    }
  }
  local_1c = (**(code **)(*local_14 + 0x34))();
  if (local_1c == -1) {
    uVar3 = 0;
  }
  else {
    FUN_012026e0(local_1c);
    for (local_18 = 1; local_18 < 4; local_18 = local_18 + 1) {
      if (local_14[0x73] != 1) {
        local_20 = 1;
        cVar1 = FUN_0117ff30(&local_20);
        if (cVar1 == '\0') {
          pQVar5 = local_2c;
          pQVar4 = (QMessageLogger *)
                   QMessageLogger::QMessageLogger(local_54,(char *)0x0,0,(char *)0x0);
          local_28 = (QDebug *)QMessageLogger::debug(pQVar4);
          local_8 = 0;
          local_24 = local_28;
          QDebug::operator<<(local_28,(char *)pQVar5);
          local_8 = 0xffffffff;
          QDebug::~QDebug(local_2c);
          if (local_18 == 3) {
            ExceptionList = local_10;
            return 0;
          }
        }
      }
    }
    if (0x2000 < local_14[0x6e]) {
      Sleep(0x32);
      iVar2 = (**(code **)(*local_14 + 0x68))();
      local_14[0x71] = iVar2;
      pcVar6 = "mBattrey:";
      pQVar5 = local_38;
      pQVar4 = (QMessageLogger *)QMessageLogger::QMessageLogger(local_68,(char *)0x0,0,(char *)0x0);
      local_34 = (QDebug *)QMessageLogger::debug(pQVar4);
      local_8 = 1;
      local_30 = local_34;
      pQVar5 = QDebug::operator<<(local_34,(char *)pQVar5);
      QDebug::operator<<(pQVar5,(int)pcVar6);
      local_8 = 0xffffffff;
      QDebug::~QDebug(local_38);
      if (local_14[0x71] != -1) {
        FUN_01202320(local_14[0x71]);
      }
    }
    uVar3 = 1;
  }
  ExceptionList = local_10;
  return uVar3;
}


/* ===== 0x117e4e0 ===== */

undefined4 FUN_0117e4e0(void)

{
  bool bVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 10) == '\0') {
    *(undefined1 *)(in_ECX + 10) = 1;
  }
  bVar1 = QTimer::isActive((QTimer *)(in_ECX + 0x64c));
  if (bVar1) {
    QTimer::stop((QTimer *)(in_ECX + 0x64c));
  }
  return 1;
}


/* ===== 0x117df00 ===== */

undefined4 FUN_0117df00(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x2d6) {
    if (param_1 < 0x2a0) {
      if (param_1 < 0x29e) {
        if (param_1 < 0x29c) {
          if (param_1 < 0x29a) {
            if (param_1 < 0x299) {
              if (param_1 < 0x297) {
                if (param_1 < 0x296) {
                  if (param_1 < 0x294) {
                    if (param_1 < 0x292) {
                      if (param_1 < 0x290) {
                        if (param_1 < 0x28e) {
                          if (param_1 < 0x28d) {
                            if (param_1 < 0x28b) {
                              if (param_1 < 0x289) {
                                if (param_1 < 0x288) {
                                  if (param_1 < 0x287) {
                                    if (param_1 < 0x284) {
                                      if (param_1 < 0x282) {
                                        if (param_1 < 0x281) {
                                          if (param_1 < 0x27f) {
                                            if (param_1 < 0x27e) {
                                              if (param_1 < 0x27c) {
                                                if (param_1 < 0x27b) {
                                                  if (param_1 < 0x279) {
                                                    if (param_1 < 0x277) {
                                                      if (param_1 < 0x275) {
                                                        if (param_1 < 0x273) {
                                                          if (param_1 < 0x272) {
                                                            if (param_1 < 0x270) {
                                                              if (param_1 < 0x268) {
                                                                if (param_1 < 0x266) {
                                                                  if (param_1 < 0x263) {
                                                                    if (param_1 < 0x260) {
                                                                      if (param_1 < 600) {
                                                                        if (param_1 < 0x254) {
                                                                          if (param_1 < 0x250) {
                                                                            if (param_1 < 0x247) {
                                                                              if (param_1 < 0x23f) {
                                                                                if (param_1 < 0x236)
                                                                                {
                                                                                  if (param_1 < 
                                                  0x22e) {
                                                    if (param_1 < 0x226) {
                                                      if (param_1 < 0x21d) {
                                                        if (param_1 == 0) {
                                                          uVar1 = 0;
                                                        }
                                                        else {
                                                          uVar1 = 0xffffffff;
                                                        }
                                                      }
                                                      else {
                                                        uVar1 = 2;
                                                      }
                                                    }
                                                    else {
                                                      uVar1 = 3;
                                                    }
                                                  }
                                                  else {
                                                    uVar1 = 4;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 6;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 7;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 8;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 10;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 0xc;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 0xe;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 0x10;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 0x13;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 0x15;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 0x17;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 0x19;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 0x1c;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 0x1e;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 0x21;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 0x23;
                                                  }
                                                  }
                                                  else {
                                                    uVar1 = 0x25;
                                                  }
                                                }
                                                else {
                                                  uVar1 = 0x29;
                                                }
                                              }
                                              else {
                                                uVar1 = 0x2d;
                                              }
                                            }
                                            else {
                                              uVar1 = 0x33;
                                            }
                                          }
                                          else {
                                            uVar1 = 0x43;
                                          }
                                        }
                                        else {
                                          uVar1 = 0x47;
                                        }
                                      }
                                      else {
                                        uVar1 = 0x4a;
                                      }
                                    }
                                    else {
                                      uVar1 = 0x4c;
                                    }
                                  }
                                  else {
                                    uVar1 = 0x4e;
                                  }
                                }
                                else {
                                  uVar1 = 0x51;
                                }
                              }
                              else {
                                uVar1 = 0x54;
                              }
                            }
                            else {
                              uVar1 = 0x56;
                            }
                          }
                          else {
                            uVar1 = 0x57;
                          }
                        }
                        else {
                          uVar1 = 0x58;
                        }
                      }
                      else {
                        uVar1 = 0x59;
                      }
                    }
                    else {
                      uVar1 = 0x5a;
                    }
                  }
                  else {
                    uVar1 = 0x5b;
                  }
                }
                else {
                  uVar1 = 0x5d;
                }
              }
              else {
                uVar1 = 0x5e;
              }
            }
            else {
              uVar1 = 0x5f;
            }
          }
          else {
            uVar1 = 0x60;
          }
        }
        else {
          uVar1 = 0x61;
        }
      }
      else {
        uVar1 = 0x62;
      }
    }
    else {
      uVar1 = 99;
    }
  }
  else {
    uVar1 = 100;
  }
  return uVar1;
}


/* ===== 0x117fde0 ===== */

void FUN_0117fde0(void)

{
  undefined4 local_3c;
  int *local_38;
  void *local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  char local_2d;
  uint local_2c [8];
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  local_34 = malloc(0x20);
  if (local_34 != (void *)0x0) {
    memset(local_34,0,0x20);
    local_2e = 0;
    local_2f = 0xa2;
    FUN_011825d0(local_34,&local_2f,&local_2e,0);
    local_2c[0] = 0;
    local_2c[1] = 0;
    local_2c[2] = 0;
    local_2c[3] = 0;
    local_2c[4] = 0;
    local_2c[5] = 0;
    local_2c[6] = 0;
    local_2c[7] = 0;
    local_c = 0;
    local_2d = 0;
    local_30 = 0xba;
    local_3c = 0x20;
    local_2d = (**(code **)(*local_38 + 0x150))(local_34,local_2c,&local_3c,&local_30);
    free(local_34);
    if (local_2d != '\0') {
      local_38[0x73] = local_2c[0] >> 8 & 0xff;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x117fee0 ===== */

undefined4 FUN_0117fee0(void)

{
  char cVar1;
  int in_ECX;
  undefined4 local_c [2];
  
  if ((*(char *)(in_ECX + 0x625) == '\0') && (*(int *)(in_ECX + 0x1cc) != 1)) {
    local_c[0] = 1;
    cVar1 = FUN_0117ff30(local_c);
    if (cVar1 == '\0') {
      return 0;
    }
  }
  return 1;
}


/* ===== 0x1182690 ===== */

void FUN_01182690(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  int local_ac;
  int local_a8;
  QMutexLocker local_a4 [7];
  undefined1 local_9d;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a;
  undefined1 local_99;
  int *local_98;
  undefined1 local_94 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01237971;
  local_10 = ExceptionList;
  uVar2 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_98 = in_ECX;
  local_14 = uVar2;
  QMutexLocker::QMutexLocker(local_a4,(QBasicMutex *)in_ECX[0x18a]);
  local_8 = 0;
  if (local_98[0x6a] == 0) {
    local_99 = 0;
    local_8 = 0xffffffff;
    QMutexLocker::~QMutexLocker(local_a4);
  }
  else {
    memset(local_94,0,0x80);
    for (local_a8 = 0; local_a8 < 3; local_a8 = local_a8 + 1) {
      if (*(char *)((int)local_98 + 9) != '\0') {
        local_9a = 0;
        local_8 = 0xffffffff;
        QMutexLocker::~QMutexLocker(local_a4);
        goto LAB_011828ab;
      }
      cVar1 = (**(code **)(*local_98 + 0x154))(param_1,param_2,param_3,uVar2);
      if (cVar1 != '\0') {
        Sleep(0x32);
        for (local_ac = 0; local_ac < 3; local_ac = local_ac + 1) {
          iVar3 = (**(code **)(*local_98 + 0x158))(local_94,param_2,param_3);
          if (iVar3 == 2) {
            Sleep(0x32);
            local_9b = 1;
            local_8 = 0xffffffff;
            QMutexLocker::~QMutexLocker(local_a4);
            goto LAB_011828ab;
          }
          if (*(char *)((int)local_98 + 9) != '\0') {
            local_9c = 0;
            local_8 = 0xffffffff;
            QMutexLocker::~QMutexLocker(local_a4);
            goto LAB_011828ab;
          }
          Sleep(0x32);
        }
      }
      Sleep(0x32);
    }
    local_9d = 0;
    local_8 = 0xffffffff;
    QMutexLocker::~QMutexLocker(local_a4);
  }
LAB_011828ab:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x11828d0 ===== */

undefined1 FUN_011828d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  int local_28;
  int local_24;
  QMutexLocker local_20 [4];
  int *local_1c;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_012379a2;
  local_10 = ExceptionList;
  uVar2 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = in_ECX;
  QMutexLocker::QMutexLocker(local_20,(QBasicMutex *)in_ECX[0x18a]);
  local_8 = 0;
  if (local_1c[0x6a] == 0) {
    local_11 = 0;
    local_8 = 0xffffffff;
    QMutexLocker::~QMutexLocker(local_20);
  }
  else {
    for (local_24 = 0; local_24 < 3; local_24 = local_24 + 1) {
      if (*(char *)((int)local_1c + 9) != '\0') {
        local_12 = 0;
        local_8 = 0xffffffff;
        QMutexLocker::~QMutexLocker(local_20);
        ExceptionList = local_10;
        return local_12;
      }
      cVar1 = (**(code **)(*local_1c + 0x154))(param_1,param_3,param_4,uVar2);
      if (cVar1 != '\0') {
        Sleep(0x32);
        for (local_28 = 0; local_28 < 3; local_28 = local_28 + 1) {
          iVar3 = (**(code **)(*local_1c + 0x158))(param_2,param_3,param_4);
          if (iVar3 == 2) {
            Sleep(0x32);
            local_13 = 1;
            local_8 = 0xffffffff;
            QMutexLocker::~QMutexLocker(local_20);
            ExceptionList = local_10;
            return local_13;
          }
          if (*(char *)((int)local_1c + 9) != '\0') {
            local_14 = 0;
            local_8 = 0xffffffff;
            QMutexLocker::~QMutexLocker(local_20);
            ExceptionList = local_10;
            return local_14;
          }
          Sleep(0x32);
        }
      }
      Sleep(0x32);
    }
    local_15 = 0;
    local_8 = 0xffffffff;
    QMutexLocker::~QMutexLocker(local_20);
    local_11 = local_15;
  }
  ExceptionList = local_10;
  return local_11;
}


/* ===== 0x1182a70 ===== */

bool FUN_01182a70(void *param_1,size_t *param_2,undefined4 param_3)

{
  char cVar1;
  void *_Dst;
  int in_ECX;
  bool bVar2;
  
  if (*(int *)(in_ECX + 0x1a8) == 0) {
    bVar2 = false;
  }
  else {
    _Dst = malloc(*param_2);
    if (_Dst == (void *)0x0) {
      bVar2 = false;
    }
    else {
      memset(_Dst,0,*param_2);
      memcpy(_Dst,param_1,*param_2);
      cVar1 = FUN_00fc6900(param_3,_Dst,*param_2 + 1);
      free(_Dst);
      bVar2 = cVar1 == '\x01';
    }
  }
  return bVar2;
}


/* ===== 0x1182b30 ===== */

undefined4 FUN_01182b30(void *param_1,size_t *param_2,undefined4 param_3)

{
  char cVar1;
  char *_Dst;
  int in_ECX;
  undefined4 local_10;
  
  if (*(int *)(in_ECX + 0x1a8) == 0) {
    local_10 = 4;
  }
  else {
    _Dst = malloc(*param_2);
    if (_Dst == (char *)0x0) {
      local_10 = 4;
    }
    else {
      memset(_Dst,0,*param_2);
      cVar1 = FUN_00fc69a0(param_3,_Dst,*param_2 + 1);
      if (cVar1 == '\x01') {
        cVar1 = *_Dst;
        if (cVar1 == '\0') {
          local_10 = 1;
        }
        else if (cVar1 == '\x01') {
          memcpy(param_1,_Dst,*param_2);
          local_10 = 2;
        }
        else if (cVar1 == '\x02') {
          local_10 = 3;
        }
      }
      else {
        local_10 = 0;
      }
      free(_Dst);
    }
  }
  return local_10;
}


/* ===== 0x112c4f0 ===== */

void FUN_0112c4f0(void)

{
  char cVar1;
  int *in_ECX;
  undefined4 local_b4;
  QObject *local_b0;
  undefined4 local_ac;
  QObject *local_a8;
  int local_a4;
  QObject *local_a0;
  int *local_9c;
  undefined1 local_98;
  undefined1 local_97;
  undefined1 local_96;
  undefined1 local_95;
  undefined1 local_94 [2];
  undefined1 uStack_92;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_01231a89;
  local_10 = ExceptionList;
  local_14 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX[0x19c] != 0) {
    local_9c = in_ECX;
    local_a4 = FUN_01209c6b(0x106c,local_14);
    local_8 = 0;
    if (local_a4 == 0) {
      local_a8 = (QObject *)0x0;
    }
    else {
      local_a8 = (QObject *)FUN_00fc5ef0(0);
    }
    local_b0 = local_a8;
    local_8 = 0xffffffff;
    local_a0 = local_a8;
    cVar1 = FUN_00fc5fe0(0x24ae,(short)local_9c[0x19c],0xe,0xff00,0);
    if (cVar1 != '\0') {
      memset(local_94,0,0x80);
      local_95 = 0;
      local_96 = 0xab;
      FUN_011825d0(local_94,&local_96,&local_95,0);
      if (local_9c[0x19c] < 0x1800) {
        local_ac = 0xb1;
      }
      else {
        local_ac = 0xb2;
      }
      uStack_92 = (undefined1)local_ac;
      local_97 = 0xba;
      local_b4 = 0x20;
      local_98 = (**(code **)(*local_9c + 0x160))(local_a0,local_94,&local_b4,&local_97);
      QObject::deleteLater(local_a0);
      local_a0 = (QObject *)0x0;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x112c6d0 ===== */

void FUN_0112c6d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  int local_90;
  undefined1 local_88 [128];
  uint local_8;
  
  local_8 = DAT_037b6510 ^ (uint)&stack0xfffffffc;
  if (param_1 != 0) {
    memset(local_88,0,0x80);
    cVar1 = (**(code **)(*in_ECX + 0x164))(param_1,param_2,param_3,param_4);
    if (cVar1 != '\0') {
      Sleep(0x32);
      for (local_90 = 0; local_90 < 3; local_90 = local_90 + 1) {
        iVar2 = (**(code **)(*in_ECX + 0x168))(param_1,local_88,param_3,param_4);
        if (iVar2 == 2) {
          Sleep(0x32);
          break;
        }
        if (*(char *)((int)in_ECX + 9) != '\0') break;
        Sleep(0x32);
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


/* ===== 0x112c7e0 ===== */

bool FUN_0112c7e0(int param_1,void *param_2,size_t *param_3,undefined4 param_4)

{
  char cVar1;
  void *_Dst;
  bool bVar2;
  
  if (param_1 == 0) {
    bVar2 = false;
  }
  else {
    _Dst = malloc(*param_3);
    if (_Dst == (void *)0x0) {
      bVar2 = false;
    }
    else {
      memset(_Dst,0,*param_3);
      memcpy(_Dst,param_2,*param_3);
      cVar1 = FUN_00fc6900(param_4,_Dst,*param_3 + 1);
      free(_Dst);
      bVar2 = cVar1 == '\x01';
    }
  }
  return bVar2;
}


/* ===== 0x112c890 ===== */

undefined4 FUN_0112c890(int param_1,void *param_2,size_t *param_3,undefined4 param_4)

{
  char cVar1;
  char *_Dst;
  undefined4 local_10;
  
  if (param_1 == 0) {
    local_10 = 4;
  }
  else {
    _Dst = malloc(*param_3);
    if (_Dst == (char *)0x0) {
      local_10 = 4;
    }
    else {
      memset(_Dst,0,*param_3);
      cVar1 = FUN_00fc69a0(param_4,_Dst,*param_3 + 1);
      if (cVar1 == '\x01') {
        cVar1 = *_Dst;
        if (cVar1 == '\0') {
          local_10 = 1;
        }
        else if (cVar1 == '\x01') {
          memcpy(param_2,_Dst,*param_3);
          local_10 = 2;
        }
        else if (cVar1 == '\x02') {
          local_10 = 3;
        }
      }
      else {
        local_10 = 0;
      }
      free(_Dst);
    }
  }
  return local_10;
}

