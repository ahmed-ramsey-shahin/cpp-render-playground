#ifndef _RGB_H_
#define _RGB_H_

class RGB {
private:
    float xyz[3];
public:
    RGB(const float, const float, const float);
    RGB();
    float& operator[](const short&);
    RGB operator+(const RGB&) const;
    RGB operator-(const RGB&) const;
    RGB operator*(const float&) const;
    RGB operator/(const float&) const;
    const float& get(const short&) const;
};

#endif // _RGB_H_
