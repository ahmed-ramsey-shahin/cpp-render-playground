#ifndef _RGB_H_
#define _RGB_H_

class rgb {
private:
    float xyz[3];
public:
    rgb(const float, const float, const float);
    rgb();
    float& operator[](const short&);
    rgb operator+(const rgb&) const;
    rgb operator-(const rgb&) const;
    rgb operator*(const float&) const;
    rgb operator/(const float&) const;
    const float& get(const short&) const;
};

#endif // _RGB_H_
