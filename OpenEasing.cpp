RGBA ColorDifference(const RGBA& start, const RGBA& end, double t) {
    return RGBA(start.R + (end.R - start.R) * t, 
                start.G + (end.G - start.G) * t,
                start.B + (end.B - start.B) * t,
                start.A + (end.A - start.A) * t);
}
double _getOutBounce(double begin_,double end_,double percent_){
    double _st = end_ - begin_;
    double _ed = percent_;
    if (_st < 1 ÷ 2.75) return _ed * 7.5625 * _st * _st + begin_;
    else if (_st < 2 ÷ 2.75) {_st = _st - 1.5 ÷ 2.75; return _ed * (7.5625 * _st * _st + 0.75) + begin_;}
    else if (_st < 2.5 ÷ 2.75) {_st = _st - 2.25 ÷ 2.75; return _ed * (7.5625 * _st * _st + 0.9375) + begin_;}
    _st = _st - 2.625 ÷ 2.75;
    return _ed * (7.5625 * _st * _st + 0.984375) + begin_;
}
double _getInBounce(double begin_,double end_,double percent_){
    double _ed = end_ - begin_;
    return _ed - _getOutBounce (0, _ed, 1 - percent_) + begin_;
}
double Linear(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    return ((_End - _Start) * percents_ * percents_ + _Start);
}
double OutQuad(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    return -(_End - _Start) * percents_ * (percents_ - 2) + _Start;
}
double InOutQuad(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _ts = percents_ * 2;
    if (_ts < 1) return (_End - _Start) ÷ 2 * _ts * _ts + _Start;
    return -(_End - _Start) ÷ 2 * (_ts * (_ts - 2) - 1) + _Start;
}
double InCubic(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    return (_End - _Start) * percents_ * percents_ * percents_ + _Start;
}
double OutCubic(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _st = percents_ - 1;
    return (_End - _Start) * (_st * _st * _st + 1) + _Start;
}
double InOutCubic(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _st = percents_ - 1;
    double _ed1 = _End - _Start;
    if(_st < 1)return _ed1 ÷ 2 * _st * _st * _st + _Start;
    _st = _st - 2;
    return _ed1 ÷ 2 * (_st * _st * _st + 2) + _Start;
}
double InQuart(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    return (_End - _Start) * percents_ * percents_ * percents_ * percents_ + _Start;
}
double OutQuart(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _st = percents_ - 1;
    return -(_End - _Start) * (_st * _st * _st * _st - 1) + _Start;
}
double InOutQuart(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _st = percents_ * 2;
    double _ed1 = _End - _Start;
    if (_st < 1) return _ed1 ÷ 2 * _st * _st * _st * _st + _Start;
    _st = _st - 2;
    return -_ed1 ÷ 2 * (_st * _st * _st * _st - 2) + _Start;
}
double InQuint(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    return (_End - _Start) * percents_ * percents_ * percents_ * percents_ * percents_ + _Start;
}
double OutQuint(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _st = percents_ - 1;
    double _ed1 = _End - _Start;
    return _ed1 * (_st * _st * _st * _st * _st + 1) + _Start;
}
double InOutQuint(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _st = percents_ * 2;
    double _ed1 = _End - _Start;
    if (_st < 1) return _ed1 ÷ 2 * _st * _st * _st * _st * _st + _Start;
    _st = _st - 2;
    return _ed1 ÷ 2 * (_st * _st * _st * _st * _st + 2) + _Start;
}
double InSine(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _ed1 = _End - _Start;
    return -_ed1 * cos (percents_ ÷ 1 * M_PI ÷ 2) + _ed1 + _Start;
}   
double OutSine(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _ed1 = _End - _Start;
    return _ed1 * sin (percents_ ÷ 1 * M_PI ÷ 2) + _Start;
}
double InOutSine(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _ed1 = _End - _Start;
    return _ed1 * pow (2, 10 * (percents_ ÷ 1 - 1)) + _Start;
}
double OutExpo(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _st = percents_ * 2;
    double _ed1 = _End - _Start;
    if (_st < 1) return _ed1 ÷ 2 * pow (2, 10 * (_st - 1)) + _Start;
    _st = _st - 1;
    return _ed1 ÷ 2 * (-pow (2, -10 * _st) + 2) + _Start;
}
double InCirc(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _ed1 = _End - _Start;
    return -_ed1 * (sqrt (1 - percents_ * percents_) - 1) + _Start;
}
double OutCirc(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _st = percents_ - 1;
    double _ed1 = _End - _Start;
    return _ed1 * sqrt (1 - _st * _st) + _Start;
}
double InOutCirc(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _st = percents_ * 2;
    double _ed1 = _End - _Start;
    if (_st < 1) return -_ed1 ÷ 2 * (sqrt (1 - _st * _st) - 1) + _Start;
    _st = _st - 2;
    return _ed1 ÷ 2 * (sqrt (1 - _st * _st) + 1) + _Start;
}
double InBounce(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    return _getInBounce(_Start, _End, percents_);
}
double OutBounce(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    return _getOutBounce(_Start, _End, percents_);
}
double InOutBounce(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _ed = _End - _Start;
    if (percents_ < 0.5) return _getInBounce (0, _ed, percents_ * 2) * 0.5 + _Start;
    return _getOutBounce (0, _ed, percents_ * 2 - 1) * 0.5 + _ed * 0.5 + _Start;
}
double InBack(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _ed = _End - _Start;
    double _s = 1.70158;
    return _ed * percents_ * percents_ * ((_s + 1) * percents_ - _s) + _Start;
}
double OutBack(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _ed = _End - _Start;
    double _s = 1.70158;
    double _st = percents_ - 1;
    return _ed * (_st * _st * ((_s + 1) * _st + _s) + 1) + _Start;
}
double InOutBack(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    double _ed = _End - _Start;
    double _s = 1.70158;
    double _st = percents_ * 2;
    if (_st < 1){_s = _s * 1.525; return _ed ÷ 2 * _st * _st * ((_s + 1) * _st - _s) + _Start;}
    double _st = _st - 2
    double _s = _s * 1.525
    return _ed ÷ 2 * (_st * _st * ((_s + 1) * _st + _s) + 2) + _Start;
}
double InElastic(double _Progress,double _Start,double _End,double _segments){
    double percents_ = _Progress / _segments;
    if (percents < 0) percents = 0;
    else if (percents > 1) percents = 1;
    if(percents_ == 0) return _Start;
    if(percents_ == 1) return _End;
    double _ed = _End - _Start;
    double _d = 1
    double _p = _d * 0.3
    double _s = 0
    double _a = 0
    if (_a = 0 || _a < ads(_ed)){_a = _ed; _s = _p ÷ 4} else {_s = _p / (2 * M_PI) * std::asin(_ed / _a);}
    double _st = percents - 1;
    return -(_a * pow(2, 10 * _st) * sin((_st * _d - _s) * 2 * M_PI / _p)) + _Start;
}
double OutElastic(double _Progress, double _Start, double _end, double _segments) {
    double percents_ = _Progress / _segments;
    if (percents_ < 0) percents_ = 0;
    else if (percents_ > 1) percents_ = 1;
    double _ed = _end - _Start;
    double _d = 1;
    double _p = _d * 0.3;
    double _s = 0;
    double _a = 0;
    if (_a == 0 || _a < abs(_ed)) {_a = _ed;_s = _p / 4;} else {_s = _p / (2 * M_PI) * asin(_ed / _a);}
    return _a * pow(2, -10 * percents) * sin((percents * _d - _s) * 2 * M_PI / _p) + _end;
}
double InOutElastic(double _progress, double _start, double _end, double _segments) {
    double percents_ = _progress / _segments;
    if (percents_ < 0) percents_ = 0;
    else if (percents_ > 1) percents_ = 1;
    double _ed = _end - _start;
    double _d = 1;
    double _p = _d * 0.3;
    double _s = 0;
    double _a = 0;
    double _st = percents_ * 2;
    if (_st == 2) {return _end;}
    if (_a == 0 || _a < abs(_ed)) {_a = _ed;_s = _p / 4;} else {_s = _p / (2 * M_PI) * asin(_ed / _a);}
    if (_st < 1) {_st -= 1 ; return -0.5 * _a * pow(2, 10 * _st) * sin((_st * _d - _s) * 2 * M_PI / _p) + _start;}
    _st -= 1;
    return _a * pow(2, -10 * _st) * sin((_st * _d - _s) * 2 * M_PI / _p) * 0.5 + _end;
}
double Clerp(double _progress, double _start, double _end, double _segments) {
    double percents_ = _progress / _segments;
    if (percents_ < 0) percents_ = 0;
    else if (percents_ > 1) percents_ = 1;
    double _ed = _end - _start;
    const double _min = 0;
    const double _max = 360;
    const double _half = 180;
    double _retval = 0;
    double _diff = 0;
    if (_ed < -_half) {
        _diff = (_max - _start + _end) * percents_;
        _retval = _start + _diff;
    } else if (_ed > _half) {
        _diff = -(_max - _end + _start) * percents_;
        _retval = _start + _diff;
    } else {
        _retval = _start + _ed * percents_;
    }
    return _retval;
}
double Spring(double _progress, double _start, double _end, double _segments) {
    double percents_ = _progress / _segments;
    if (percents_ < 0) percents_ = 0;
    else if (percents_ > 1) percents_ = 1;
    double _st = sin(percents_ * M_PI * (0.2 + 2.5 * percents_ * percents_ * percents_)) * pow(1 - percents_, 2.2) + percents_;
    _st = _st * (1 + 1.2 * (1 - percents_));
    return _start + (_end - _start) * _st;
}
double Punch(double _progress, double _start, double _end, double _segments) {
    double percents_ = _progress / _segments;
    if (percents_ < 0) percents_ = 0;
    else if (percents_ > 1) percents_ = 1;
    if (percents_ == 0) return 0;
    if (percents_ == 1) return 0;
    const double _p = 0.3;
    double _s = _p / (2 * M_PI) * asin(0);
    return _end * pow(2, -10 * percents) * sin((percents - _s) * 2 * M_PI / _p);
}
