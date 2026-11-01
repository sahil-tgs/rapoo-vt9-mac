
undefined1 FUN_011817e0(int *param_1,undefined1 *param_2,int param_3,undefined1 param_4)

{
  QMessageLogger *this;
  QDebug *pQVar1;
  QMessageLogger local_3c [24];
  QDebug local_24 [4];
  QDebug *local_20;
  QDebug *local_1c;
  int local_18;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0123794a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_11 = 1;
  local_18 = *param_1 + 1;
  switch(*param_1) {
  case 0:
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    break;
  case 1:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = 4;
    param_2[3] = 0x3d;
    break;
  case 2:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = 8;
    param_2[3] = 0xf;
    break;
  case 3:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = 8;
    param_2[3] = 0x15;
    break;
  case 4:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = 8;
    param_2[3] = 7;
    break;
  default:
    pQVar1 = local_24;
    this = (QMessageLogger *)QMessageLogger::QMessageLogger(local_3c,(char *)0x0,0,(char *)0x0);
    local_20 = (QDebug *)QMessageLogger::debug(this);
    local_8 = 0;
    local_1c = local_20;
    QDebug::operator<<(local_20,(char *)pQVar1);
    local_8 = 0xffffffff;
    QDebug::~QDebug(local_24);
    local_11 = 0;
    break;
  case 6:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = 4;
    param_2[3] = 0x2b;
    break;
  case 7:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = 1;
    param_2[3] = 0x57;
    break;
  case 8:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = 1;
    param_2[3] = 0x56;
    break;
  case 9:
    *param_2 = 3;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 1;
    param_2[3] = 0;
    break;
  case 10:
    *param_2 = 3;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 4;
    param_2[3] = 0;
    break;
  case 0xb:
    *param_2 = 3;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 2;
    param_2[3] = 0;
    break;
  case 0xc:
    *param_2 = 3;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 0x10;
    param_2[3] = 0;
    break;
  case 0xd:
    *param_2 = 3;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 8;
    param_2[3] = 0;
    break;
  case 0xe:
    *param_2 = 3;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 0x10;
    param_2[3] = 0;
    break;
  case 0xf:
    *param_2 = 3;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 8;
    param_2[3] = 0;
    break;
  case 0x10:
    *param_2 = 3;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 0x10;
    param_2[3] = 0;
    break;
  case 0x11:
    *param_2 = 3;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 8;
    param_2[3] = 0;
    break;
  case 0x12:
    *param_2 = 4;
    param_2[1] = 0;
    param_2[2] = 1;
    param_2[3] = 0x83;
    break;
  case 0x13:
    *param_2 = 4;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0xcd;
    break;
  case 0x14:
    *param_2 = 4;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0xb7;
    break;
  case 0x15:
    *param_2 = 4;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0xb6;
    break;
  case 0x16:
    *param_2 = 4;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0xb5;
    break;
  case 0x17:
    *param_2 = 4;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0xea;
    break;
  case 0x18:
    *param_2 = 4;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0xe9;
    break;
  case 0x19:
    *param_2 = 4;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0xe2;
    break;
  case 0x1a:
    *param_2 = 9;
    param_2[1] = 0;
    param_2[2] = 1;
    param_2[3] = 0;
    break;
  case 0x1b:
    *param_2 = 3;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 1;
    param_2[3] = 1;
    break;
  case 0x1c:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = 1;
    param_2[3] = 9;
    break;
  case 0x1d:
    *param_2 = 5;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = 0;
    break;
  case 0x1e:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0x20:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0x21:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0x22:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0x23:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0x24:
    *param_2 = 8;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 3;
    param_2[3] = 0;
    break;
  case 0x25:
    *param_2 = 0xff;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0xff;
    }
    param_2[2] = 0xff;
    param_2[3] = 0xff;
    break;
  case 0x26:
    *param_2 = 0xff;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0xff;
    }
    param_2[2] = 0xff;
    param_2[3] = 0xff;
    break;
  case 0x27:
    *param_2 = 8;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 5;
    param_2[3] = 0;
    break;
  case 0x28:
    *param_2 = 8;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 6;
    param_2[3] = 0;
    break;
  case 0x29:
    *param_2 = 9;
    param_2[1] = 0;
    param_2[2] = 3;
    param_2[3] = 0;
    break;
  case 0x2a:
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = param_4;
    param_2[3] = 0;
    break;
  case 0x2f:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0x30:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0x31:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0x32:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0x33:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0x34:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0x35:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0x36:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0x37:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0x38:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0x39:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = (undefined1)param_3;
    param_2[3] = param_4;
    break;
  case 0xb7:
    *param_2 = 0xff;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0xff;
    }
    param_2[2] = 0xff;
    param_2[3] = 0xff;
    break;
  case 0xb8:
    *param_2 = 0xff;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0xff;
    }
    param_2[2] = 0xff;
    param_2[3] = 0xff;
    break;
  case 0xba:
    *param_2 = 10;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 0;
    param_2[3] = 0;
    break;
  case 0xbb:
    *param_2 = 10;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 1;
    param_2[3] = 0;
    break;
  case 0xbc:
    *param_2 = 10;
    if (param_3 == 1) {
      param_2[1] = 1;
    }
    else {
      param_2[1] = 0;
    }
    param_2[2] = 2;
    param_2[3] = 0;
    break;
  case 0xc6:
    *param_2 = 4;
    param_2[1] = 0;
    param_2[2] = 1;
    param_2[3] = 0x8a;
    break;
  case 199:
    *param_2 = 4;
    param_2[1] = 0;
    param_2[2] = 1;
    param_2[3] = 0x92;
    break;
  case 200:
    *param_2 = 4;
    param_2[1] = 0;
    param_2[2] = 1;
    param_2[3] = 0x94;
    break;
  case 0xc9:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = 1;
    param_2[3] = 6;
    break;
  case 0xca:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = 1;
    param_2[3] = 0x19;
    break;
  case 0xcb:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = 1;
    param_2[3] = 0x1b;
    break;
  case 0xcc:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = 1;
    param_2[3] = 4;
    break;
  case 0xcd:
    *param_2 = 2;
    param_2[1] = 0;
    param_2[2] = 8;
    param_2[3] = 0x2e;
    break;
  case -1:
    *param_2 = 7;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
  }
  ExceptionList = local_10;
  return local_11;
}


=====

undefined1 *
FUN_010e3880(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined1 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_3;
  in_ECX[2] = param_2;
  in_ECX[3] = param_4;
  return in_ECX;
}


=====
