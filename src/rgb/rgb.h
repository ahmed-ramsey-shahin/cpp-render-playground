#ifndef _RGB_H_
#define _RGB_H_

class rgb {
private:
    unsigned char xyz[3];
public:
    rgb(const unsigned char, const unsigned char, const unsigned char);
    rgb();
    unsigned char& operator[](const short&);
    rgb operator+(const rgb&) const;
    rgb operator-(const rgb&) const;
    rgb operator*(const unsigned char&) const;
    rgb operator/(const unsigned char&) const;
    const unsigned char& get(const short&) const;
};

#endif // _RGB_H_
