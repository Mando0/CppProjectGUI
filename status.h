#ifndef status_h
#define status_h 2016

class Status {
public:
    Status(bool is_Available): isAvailable(is_Available){}
    bool get_status() {
        return isAvailable;
    }
private:
    bool isAvailable;
};
#endif
