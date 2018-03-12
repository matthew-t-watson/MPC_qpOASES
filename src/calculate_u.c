/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_u.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 12-Mar-2018 14:11:24
 */

/* Include Files */
#include "calculate_u.h"

/* Function Definitions */

/*
 * CALCULATE_U Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double x[8]
 *                const double r[160]
 *                const double c[80]
 *                double u[4]
 * Return Type  : void
 */
void calculate_u(const double x[8], const double r[160], const double c[80],
                 double u[4])
{
  int i0;
  double a[4];
  int i1;
  double b_a[4];
  static const double c_a[32] = { 4.2798471313115343, -4.2798471313115023,
    -4.2798471313115014, 4.2798471313115387, 3.5755894736631375,
    3.5755894736631593, 3.5755894736632032, 3.5755894736632987,
    -1.4730206864601769, -0.883812411876104, 0.88381241187611226,
    1.4730206864601851, 1.6838945269403229, 1.6838945269403334,
    1.6838945269403391, 1.683894526940372, 0.445722774711624,
    -0.44572277471162308, -0.44572277471162297, 0.44572277471162453,
    1.4160877477713785, 1.4160877477713925, 1.4160877477713973,
    1.4160877477714322, -0.09533439839769893, -0.057200639038619307,
    0.057200639038619577, 0.095334398397699249, 0.25904072469695583,
    0.25904072469695744, 0.25904072469695866, 0.25904072469696326 };

  static const double d_a[640] = { -3.135774054828139, 3.1357740548281017,
    3.1357740548281088, -3.1357740548281439, -1.8285335850974118,
    -1.8285335850974289, -1.8285335850974394, -1.8285335850975128,
    0.86935156809261016, 0.52161094085556314, -0.52161094085556847,
    -0.86935156809261138, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.87956109824000772,
    -0.87956109824000872, -0.87956109824000228, 0.87956109824000617,
    1.3535438477616684, 1.3535438477616724, 1.3535438477616943,
    1.3535438477617072, -0.37054647866767143, -0.22232788720060406,
    0.22232788720060581, 0.37054647866767737, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.56048024607287061, -0.56048024607284064, -0.56048024607283964,
    0.560480246072874, 1.1081937457266835, 1.1081937457266851,
    1.1081937457266986, 1.108193745726705, -0.1140289066563423,
    -0.068417343993806681, 0.0684173439938066, 0.11402890665634623, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.30344081175213233, -0.30344081175206861,
    -0.30344081175206922, 0.30344081175213516, 0.81457768781269413,
    0.81457768781269579, 0.81457768781270212, 0.81457768781270279,
    0.049613645662078494, 0.029768187397245433, -0.029768187397247885,
    -0.049613645662077058, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.10252257693644645,
    -0.1025225769363584, -0.10252257693636069, 0.10252257693644806,
    0.52037906412381885, 0.52037906412382007, 0.52037906412382084,
    0.52037906412381818, 0.140862616081717, 0.084517569649028262,
    -0.084517569649032523, -0.1408626160817176, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.048940552420455787, 0.048940552420555908, 0.048940552420552279,
    -0.048940552420456321, 0.2546329563466167, 0.254632956346617,
    0.25463295634661559, 0.25463295634661071, 0.17958313688279084,
    0.10774988212967253, -0.1077498821296777, -0.17958313688279276, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -0.15788458764744323, 0.15788458764754293,
    0.15788458764753821, -0.1578845876474452, 0.0324773855184917,
    0.032477385518492927, 0.032477385518490304, 0.032477385518483691,
    0.18314246984655724, 0.1098854819079325, -0.1098854819079378,
    -0.18314246984655966, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.23115553163430683,
    0.23115553163439562, 0.23115553163439032, -0.23115553163430866,
    -0.14075447122376314, -0.14075447122376197, -0.14075447122376511,
    -0.14075447122377105, 0.1655678883881658, 0.099340733032897879,
    -0.099340733032902653, -0.16556788838816813, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.27524940155238814, 0.27524940155245886, 0.27524940155245403,
    -0.27524940155238975, -0.26619143754310337, -0.26619143754310259,
    -0.26619143754310448, -0.26619143754311075, 0.13740849340792974,
    0.082445096044756541, -0.082445096044760358, -0.13740849340793157, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -0.29613626852213687, 0.296136268522186, 0.29613626852218111,
    -0.29613626852213837, -0.34882374291934015, -0.34882374291933943,
    -0.34882374291934037, -0.34882374291934565, 0.10602732406753064,
    0.063616394440517449, -0.063616394440520127, -0.10602732406753178, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -0.29915315565071343, 0.29915315565073997,
    0.29915315565073552, -0.29915315565071515, -0.39557804091165916,
    -0.395578040911659, -0.39557804091165821, -0.39557804091166165,
    0.076116039408903838, 0.045669623645341675, -0.045669623645343216,
    -0.0761160394089042, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.28895183109099382,
    0.28895183109099842, 0.2889518310909947, -0.28895183109099537,
    -0.41397029652039252, -0.41397029652039263, -0.41397029652039108,
    -0.41397029652039374, 0.050285664540685886, 0.030171398724411203,
    -0.030171398724411706, -0.050285664540685539, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.26948898783143915, 0.26948898783142422, 0.26948898783142122,
    -0.26948898783144, -0.411227812320355, -0.41122781232035527,
    -0.41122781232035271, -0.41122781232035333, 0.029638764181597995,
    0.0177832585089587, -0.017783258508958368, -0.029638764181597072, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -0.24404788698772895, 0.24404788698769839,
    0.24404788698769594, -0.24404788698772945, -0.39377400774081212,
    -0.39377400774081273, -0.39377400774081034, -0.3937740077408094,
    0.014269185584428913, 0.0085615113506574449, -0.0085615113506564942,
    -0.014269185584427618, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.21528215591620373,
    0.21528215591616096, 0.21528215591615943, -0.21528215591620356,
    -0.36697993464255596, -0.36697993464255729, -0.36697993464255391,
    -0.36697993464255274, 0.0036653661035142802, 0.00219921966210879,
    -0.0021992196621074449, -0.0036653661035127663, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.18527400163645541, 0.18527400163640473, 0.18527400163640378,
    -0.1852740016364548, -0.33510095954794133, -0.33510095954794278,
    -0.33510095954793978, -0.33510095954793739, -0.0029866016003580477,
    -0.0017919609602145281, 0.0017919609602160755, 0.0029866016003596237, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -0.15560057086303575, 0.1556005708629809,
    0.15560057086298049, -0.15560057086303483, -0.30133279325162132,
    -0.30133279325162371, -0.30133279325162021, -0.30133279325161733,
    -0.0065916243772122457, -0.0039549746263270076, 0.003954974626328601,
    0.0065916243772137628, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.12740352567254309,
    0.12740352567248739, 0.12740352567248731, -0.12740352567254204,
    -0.26793628135376324, -0.2679362813537659, -0.26793628135376252,
    -0.26793628135375935, -0.0080111000842445438, -0.0048066600505463812,
    0.0048066600505479043, 0.00801110008424592, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.1014580885467503, 0.10145808854669633, 0.10145808854669654,
    -0.10145808854674909, -0.23639400515699441, -0.23639400515699774,
    -0.23639400515699452, -0.23639400515699102, -0.0079882072007428622,
    -0.0047929243204453886, 0.0047929243204467668, 0.0079882072007440522, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -0.094064060405722655, 0.09406406040557605,
    0.094064060405582364, -0.094064060405714425, -1.9526142816044028,
    -1.9526142816044383, -1.9526142816044145, -1.9526142816043779,
    -0.022358366709672235, -0.01341502002580148, 0.013415020025808166,
    0.022358366709677131, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  for (i0 = 0; i0 < 4; i0++) {
    a[i0] = 0.0;
    for (i1 = 0; i1 < 8; i1++) {
      a[i0] += c_a[i0 + (i1 << 2)] * x[i1];
    }

    b_a[i0] = 0.0;
    for (i1 = 0; i1 < 160; i1++) {
      b_a[i0] += d_a[i0 + (i1 << 2)] * r[i1];
    }

    u[i0] = (a[i0] + b_a[i0]) + c[i0];
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void calculate_u_initialize(void)
{
}

/*
 * File trailer for calculate_u.c
 *
 * [EOF]
 */
