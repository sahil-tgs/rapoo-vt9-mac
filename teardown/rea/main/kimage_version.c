
void FUN_01030470(void)

{
  char cVar1;
  int iVar2;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 local_5c;
  undefined1 local_5b;
  undefined1 local_5a;
  undefined1 local_59;
  undefined1 local_58;
  undefined1 local_57;
  undefined1 local_56;
  undefined1 local_55;
  undefined1 local_54;
  undefined1 local_53;
  undefined1 local_52;
  undefined1 local_51;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  undefined1 local_48;
  undefined1 local_47;
  undefined1 local_46;
  undefined1 local_45;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  int local_8;
  
  FUN_00fcf2c0();
  local_64 = FUN_01163ce0();
  cVar1 = FUN_00fc03c0(&local_64);
  if (cVar1 == '\0') {
    return;
  }
  local_5e = 0;
  FUN_01029420(&local_5e);
  FUN_011f7230();
  if (*(char *)(local_8 + 0xc2) == '\0') {
    FUN_00fcf2c0();
    local_74 = FUN_01163ce0();
    cVar1 = FUN_00fc03c0(&local_74);
    if (cVar1 != '\0') {
      iVar2 = QString::toInt((QString *)(local_8 + 0x44),(bool *)0x0,10);
      if ((iVar2 < 0x6d) ||
         (iVar2 = QString::toInt((QString *)(local_8 + 0x44),(bool *)0x0,10), 199 < iVar2)) {
        FUN_010290c0(0);
        FUN_01028f70(1);
        FUN_01028fb0(0);
        FUN_01029100(0);
        local_1f = 0;
        FUN_01029200(&local_1f);
        local_20 = 0;
        FUN_01029240(&local_20);
        local_21 = 0;
        FUN_01029280(&local_21);
        local_22 = 0;
        FUN_010292c0(&local_22);
        local_23 = 0;
        FUN_01029300(&local_23);
        local_24 = 0;
        FUN_01029340(&local_24);
        local_25 = 0;
        FUN_01029380(&local_25);
        FUN_011f71d0();
        FUN_011f7110();
        FUN_011f7140();
        FUN_011f7170();
        FUN_011f71a0();
        FUN_011f6fc0();
        FUN_011f6f00();
        FUN_011f6f30();
        FUN_011f6ff0();
        FUN_011f70b0();
        FUN_011f70e0();
      }
      else {
        FUN_010290c0(0);
        FUN_01028f70(0);
        FUN_01028fb0(1);
        FUN_01029100(1);
        local_18 = 0;
        FUN_01029240(&local_18);
        local_19 = 0;
        FUN_01029200(&local_19);
        local_1a = 0;
        FUN_01029380(&local_1a);
        FUN_011f71d0();
        FUN_011f6fc0();
        FUN_011f6f00();
        FUN_011f6f30();
        FUN_011f6ff0();
        FUN_011f70e0();
        FUN_011f70b0();
        local_1b = 0;
        FUN_01029280(&local_1b);
        local_1c = 0;
        FUN_010292c0(&local_1c);
        local_1d = 0;
        FUN_01029300(&local_1d);
        local_1e = 0;
        FUN_01029340(&local_1e);
        FUN_011f7110();
        FUN_011f7140();
        FUN_011f7170();
        FUN_011f71a0();
      }
      FUN_00fcf2c0();
      local_78 = FUN_01163ce0();
      cVar1 = FUN_00fc03c0(&local_78);
      if ((cVar1 != '\0') &&
         (iVar2 = QString::toInt((QString *)(local_8 + 0x44),(bool *)0x0,10), 199 < iVar2)) {
        local_26 = 1;
        FUN_01029200(&local_26);
        local_27 = 1;
        FUN_01029240(&local_27);
        local_28 = 0;
        FUN_01029280(&local_28);
        local_29 = 0;
        FUN_010292c0(&local_29);
        local_2a = 1;
        FUN_01029300(&local_2a);
        local_2b = 1;
        FUN_01029340(&local_2b);
        local_2c = 1;
        FUN_01029380(&local_2c);
        FUN_011f71d0();
        FUN_011f7110();
        FUN_011f7140();
        FUN_011f7170();
        FUN_011f71a0();
        FUN_011f70b0();
        FUN_011f70b0();
        FUN_011f70e0();
        FUN_01028fb0(1);
        FUN_011f6f30();
      }
      FUN_00fcf2c0();
      local_7c = FUN_01163ce0();
      cVar1 = FUN_00fc03c0(&local_7c);
      if ((cVar1 != '\0') &&
         (iVar2 = QString::toInt((QString *)(local_8 + 0x44),(bool *)0x0,10), 199 < iVar2)) {
        local_2d = 1;
        FUN_01029200(&local_2d);
        local_2e = 1;
        FUN_01029240(&local_2e);
        local_2f = 0;
        FUN_01029280(&local_2f);
        local_30 = 0;
        FUN_010292c0(&local_30);
        local_31 = 1;
        FUN_01029300(&local_31);
        local_32 = 1;
        FUN_01029340(&local_32);
        local_33 = 1;
        FUN_01029380(&local_33);
        FUN_011f71d0();
        FUN_011f7110();
        FUN_011f7140();
        FUN_011f7170();
        FUN_011f71a0();
        FUN_011f70b0();
        FUN_011f70b0();
        FUN_011f70e0();
        FUN_01028fb0(1);
        FUN_011f6f30();
      }
      FUN_00fcf2c0();
      local_80 = FUN_01163ce0();
      cVar1 = FUN_00fc03c0(&local_80);
      if ((cVar1 != '\0') &&
         (iVar2 = QString::toInt((QString *)(local_8 + 0x44),(bool *)0x0,10), 199 < iVar2)) {
        FUN_010290c0(0);
        FUN_01028f70(0);
        FUN_01028fb0(1);
        FUN_01029100(0);
        FUN_011f6fc0();
        FUN_011f6f00();
        FUN_011f6f30();
        FUN_011f6ff0();
        local_34 = 1;
        FUN_01029200(&local_34);
        local_35 = 1;
        FUN_01029240(&local_35);
        local_36 = 0;
        FUN_01029280(&local_36);
        local_37 = 0;
        FUN_010292c0(&local_37);
        local_38 = 0;
        FUN_01029300(&local_38);
        local_39 = 0;
        FUN_01029340(&local_39);
        local_3a = 1;
        FUN_01029380(&local_3a);
        FUN_011f71d0();
        FUN_011f7110();
        FUN_011f7140();
        FUN_011f7170();
        FUN_011f71a0();
        FUN_011f70b0();
        FUN_011f70e0();
      }
      FUN_00fcf2c0();
      local_84 = FUN_01163ce0();
      cVar1 = FUN_00fc03c0(&local_84);
      if ((cVar1 != '\0') &&
         (iVar2 = QString::toInt((QString *)(local_8 + 0x44),(bool *)0x0,10), 199 < iVar2)) {
        FUN_010290c0(0);
        FUN_01028f70(0);
        FUN_01028fb0(1);
        FUN_01029100(1);
        FUN_011f6fc0();
        FUN_011f6f00();
        FUN_011f6f30();
        FUN_011f6ff0();
        local_3b = 1;
        FUN_01029200(&local_3b);
        local_3c = 1;
        FUN_01029240(&local_3c);
        local_3d = 1;
        FUN_01029280(&local_3d);
        local_3e = 1;
        FUN_010292c0(&local_3e);
        local_3f = 1;
        FUN_01029300(&local_3f);
        local_40 = 1;
        FUN_01029340(&local_40);
        local_41 = 0;
        FUN_01029380(&local_41);
        FUN_011f71d0();
        FUN_011f7110();
        FUN_011f7140();
        FUN_011f7170();
        FUN_011f71a0();
        FUN_011f70b0();
        FUN_011f70b0();
        FUN_011f70e0();
      }
    }
    FUN_00fcf2c0();
    local_88 = FUN_01163ce0();
    cVar1 = FUN_00fc03c0(&local_88);
    if (cVar1 == '\0') {
      return;
    }
    iVar2 = QString::toInt((QString *)(local_8 + 0x44),(bool *)0x0,10);
    if (0xe0 < iVar2) {
      FUN_010290c0(1);
      FUN_01028f70(0);
      FUN_01028fb0(1);
      FUN_01029100(1);
      local_42 = 1;
      FUN_01029200(&local_42);
      local_43 = 1;
      FUN_01029240(&local_43);
      local_44 = 1;
      FUN_01029280(&local_44);
      local_45 = 1;
      FUN_010292c0(&local_45);
      local_46 = 1;
      FUN_01029300(&local_46);
      local_47 = 1;
      FUN_01029340(&local_47);
      local_48 = 0;
      FUN_01029380(&local_48);
      FUN_011f71d0();
      FUN_011f7110();
      FUN_011f7140();
      FUN_011f7170();
      FUN_011f71a0();
      FUN_011f70b0();
      FUN_011f6fc0();
      FUN_011f6f00();
      FUN_011f6f30();
      FUN_011f6ff0();
      FUN_011f70e0();
      return;
    }
    iVar2 = QString::toInt((QString *)(local_8 + 0x44),(bool *)0x0,10);
    if (0xdb < iVar2) {
      FUN_010290c0(1);
      FUN_01028f70(0);
      FUN_01028fb0(1);
      FUN_01029100(1);
      local_49 = 1;
      FUN_01029200(&local_49);
      local_4a = 0;
      FUN_01029240(&local_4a);
      local_4b = 1;
      FUN_01029280(&local_4b);
      local_4c = 1;
      FUN_010292c0(&local_4c);
      local_4d = 1;
      FUN_01029300(&local_4d);
      local_4e = 1;
      FUN_01029340(&local_4e);
      local_4f = 1;
      FUN_01029380(&local_4f);
      FUN_011f71d0();
      FUN_011f7110();
      FUN_011f7140();
      FUN_011f7170();
      FUN_011f71a0();
      FUN_011f6fc0();
      FUN_011f6f00();
      FUN_011f6f30();
      FUN_011f6ff0();
      FUN_011f70b0();
      FUN_011f70e0();
      return;
    }
    iVar2 = QString::toInt((QString *)(local_8 + 0x44),(bool *)0x0,10);
    if (0xd4 < iVar2) {
      FUN_010290c0(1);
      FUN_01028f70(0);
      FUN_01028fb0(1);
      FUN_01029100(1);
      local_50 = 0;
      FUN_01029200(&local_50);
      local_51 = 0;
      FUN_01029240(&local_51);
      local_52 = 0;
      FUN_01029280(&local_52);
      local_53 = 0;
      FUN_010292c0(&local_53);
      local_54 = 0;
      FUN_01029300(&local_54);
      local_55 = 0;
      FUN_01029340(&local_55);
      local_56 = 1;
      FUN_01029380(&local_56);
      FUN_011f71d0();
      FUN_011f7110();
      FUN_011f7140();
      FUN_011f7170();
      FUN_011f71a0();
      FUN_011f6fc0();
      FUN_011f6f00();
      FUN_011f6f30();
      FUN_011f6ff0();
      FUN_011f70b0();
      FUN_011f70e0();
      return;
    }
    FUN_010290c0(0);
    FUN_01028f70(1);
    FUN_01028fb0(0);
    FUN_01029100(0);
    local_57 = 0;
    FUN_01029200(&local_57);
    local_58 = 0;
    FUN_01029240(&local_58);
    local_59 = 0;
    FUN_01029280(&local_59);
    local_5a = 0;
    FUN_010292c0(&local_5a);
    local_5b = 0;
    FUN_01029300(&local_5b);
    local_5c = 0;
    FUN_01029340(&local_5c);
    local_5d = 1;
    FUN_01029380(&local_5d);
    FUN_011f71d0();
    FUN_011f7110();
    FUN_011f7140();
    FUN_011f7170();
    FUN_011f71a0();
    FUN_011f6fc0();
    FUN_011f6f00();
    FUN_011f6f30();
    FUN_011f6ff0();
    FUN_011f70b0();
    FUN_011f70e0();
    return;
  }
  iVar2 = QString::toInt((QString *)(local_8 + 0x44),(bool *)0x0,10);
  if (iVar2 < 0x6c) {
    *(undefined1 *)(local_8 + 0xc4) = 1;
    FUN_011f7080();
  }
  else {
    *(undefined1 *)(local_8 + 0xc4) = 0;
    FUN_011f7080();
  }
  iVar2 = QString::toInt((QString *)(local_8 + 0x44),(bool *)0x0,10);
  if (iVar2 < 0x6c) {
    local_9 = 0;
    FUN_01029200(&local_9);
    local_a = 0;
    FUN_01029280(&local_a);
    local_b = 0;
    FUN_010292c0(&local_b);
    local_c = 0;
    FUN_01029300(&local_c);
    local_d = 0;
    FUN_01029340(&local_d);
    FUN_011f7110();
    FUN_011f7140();
    FUN_011f7170();
    FUN_011f71a0();
    FUN_011f70b0();
  }
  else {
    local_e = 1;
    FUN_01029200(&local_e);
    local_f = 0;
    FUN_01029280(&local_f);
    local_10 = 1;
    FUN_010292c0(&local_10);
    local_11 = 1;
    FUN_01029300(&local_11);
    local_12 = 1;
    FUN_01029340(&local_12);
    FUN_011f7110();
    FUN_011f7140();
    FUN_011f7170();
    FUN_011f71a0();
    FUN_011f70b0();
  }
  iVar2 = QString::toInt((QString *)(local_8 + 0x44),(bool *)0x0,10);
  if (iVar2 < 0x72) {
    local_13 = 0;
    FUN_01029240(&local_13);
    FUN_011f70e0();
  }
  else {
    local_14 = 1;
    FUN_01029240(&local_14);
    FUN_011f70e0();
  }
  iVar2 = QString::toInt((QString *)(local_8 + 0x44),(bool *)0x0,10);
  if (0xdd < iVar2) {
    local_15 = 1;
    FUN_01029280(&local_15);
    FUN_011f7110();
    FUN_00fcf2c0();
    local_68 = FUN_01163ce0();
    cVar1 = FUN_00fc03c0(&local_68);
    if (cVar1 == '\0') {
      FUN_00fcf2c0();
      local_6c = FUN_01163ce0();
      cVar1 = FUN_00fc03c0(&local_6c);
      if (cVar1 == '\0') goto LAB_010306e7;
    }
    local_16 = 1;
    FUN_01029420(&local_16);
    FUN_011f7230();
  }
LAB_010306e7:
  FUN_010290c0(1);
  FUN_011f6fc0();
  FUN_01028f70(0);
  FUN_011f6f00();
  FUN_01028fb0(1);
  FUN_011f6f30();
  FUN_01029100(1);
  FUN_011f6ff0();
  local_17 = 0;
  FUN_01029380(&local_17);
  FUN_011f71d0();
  FUN_00fcf2c0();
  local_70 = FUN_01163ce0();
  cVar1 = FUN_00fc03c0(&local_70);
  if (cVar1 != '\0') {
    FUN_01029100(0);
    FUN_011f6ff0();
  }
  return;
}


=====
