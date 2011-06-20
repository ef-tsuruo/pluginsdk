#include "sxsdk.cxx"

const sxsdk::mat4 sxsdk::mat4::identity(1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0);
const sxsdk::mat4 sxsdk::mat4::zero(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

const sx::vec<float,3> sxsdk::color3::black(0.0, 0.0, 0.0);
const sx::vec<float,3> sxsdk::color3::dark_gray(0.25, 0.25, 0.25);
const sx::vec<float,3> sxsdk::color3::gray(0.5, 0.5, 0.5);
const sx::vec<float,3> sxsdk::color3::light_gray(0.85, 0.85, 0.85);
const sx::vec<float,3> sxsdk::color3::white(1.0, 1.0, 1.0);
const sx::vec<float,3> sxsdk::color3::red(1.0, 0.0, 0.0);
const sx::vec<float,3> sxsdk::color3::green(0.0, 1.0, 0.0);
const sx::vec<float,3> sxsdk::color3::blue(0.0, 0.0, 1.0);
const sx::vec<float,3> sxsdk::color3::yellow(1.0, 1.0, 0.0);
const sx::vec<float,3> sxsdk::color3::magenta(1.0, 0.0, 1.0);
const sx::vec<float,3> sxsdk::color3::cyan(0.0, 1.0, 1.0);

const sx::vec<float,4> sxsdk::color4::black(0.0, 0.0, 0.0, 1.0);
const sx::vec<float,4> sxsdk::color4::dark_gray(0.25f, 0.25f, 0.25f, 1.0);
const sx::vec<float,4> sxsdk::color4::gray(0.5, 0.5, 0.5, 1.0);
const sx::vec<float,4> sxsdk::color4::light_gray(0.85f, 0.85f, 0.85f, 1.0);
const sx::vec<float,4> sxsdk::color4::white(1.0, 1.0, 1.0, 1.0);
const sx::vec<float,4> sxsdk::color4::red(1.0, 0.0, 0.0, 1.0);
const sx::vec<float,4> sxsdk::color4::green(0.0, 1.0, 0.0, 1.0);
const sx::vec<float,4> sxsdk::color4::blue(0.0, 0.0, 1.0, 1.0);
const sx::vec<float,4> sxsdk::color4::yellow(1.0, 1.0, 0.0, 1.0);
const sx::vec<float,4> sxsdk::color4::magenta(1.0, 0.0, 1.0, 1.0);
const sx::vec<float,4> sxsdk::color4::cyan(0.0, 1.0, 1.0, 1.0);

const sxsdk::quaternion_class sxsdk::quaternion_class::identity(1.0, 0.0, 0.0, 0.0);
const sxsdk::quaternion_class sxsdk::quaternion_class::zero(0.0, 0.0, 0.0, 0.0);
