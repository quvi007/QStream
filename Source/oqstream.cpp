//
// Created by Quvi on 3/22/2020.
//

#include "qstream.h"

oqstream::oqstream() : oqstream(nullptr) {

}

oqstream::oqstream(const char *loc, const char *open_mode) : qstream(loc, open_mode) {

}

oqstream::oqstream(oqstream &&source) : qstream(std::move(source)) {

}

oqstream &oqstream::operator=(oqstream &&rhs) {
    qstream::operator=(std::move(rhs));
    return *this;
}

oqstream &oqstream::operator<<(const char *buff) {

    return *this;
}

oqstream &oqstream::write(const char *buff, int size) {
    if (fp)
        fwrite(buff, sizeof(char), size, fp);
    return *this;
}

void oqstream::close() {
    qstream::close();
}

int oqstream::tellp() const {
    return tell();
}

void oqstream::seekp(int offset, int direction) {
    seek(offset, direction);
}

oqstream &oqstream::put(const unsigned char ch) {
    putc(ch, fp);
    return *this;
}

oqstream &oqstream::rewind() {
    qstream::qrewind();
    return *this;
}