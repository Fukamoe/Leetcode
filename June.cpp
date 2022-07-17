class MovingAverage {
public:
    MovingAverage(int size) {
        this->size = size;
        this->sum = 0.0;
    }
    
    double next(int val) {
        if (qu.size() == size) {
            sum -= qu.front();
            qu.pop();
        }
        qu.emplace(val);
        sum += val;
