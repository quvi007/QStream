//
// Created by Quvi on 3/22/2020.
//

#include "qstream.h"

iqstream::iqstream() : iqstream(nullptr) {

}

iqstream::iqstream(const char *loc, const char *open_mode) : qstream(loc, open_mode) {

}

iqstream::iqstream(iqstream &&source) : qstream(std::move(source)) {

}

iqstream &iqstream::operator=(iqstream &&rhs) {
    qstream::operator=(std::move(rhs));
    return *this;
}

iqstream &iqstream::operator>>(int &a) {
    fscanf(fp, "%d", &a);
    return *this;
}


iqstream &iqstream::read(char *buff, int size) {
    if (fp)
        fread(buff, sizeof(char), size, fp);
    return *this;
}

void iqstream::close() {
    qstream::close();
}

int iqstream::tellg() const {
    return tell();
}

void iqstream::seekg(int offset, int direction) {
    seek(offset, direction);
}

iqstream &iqstream::get(char &ch) {
    char x = getc(fp);
    //if(feof(fp)) return NULL;
    ch = x;
    return *this;
}

iqstream &iqstream::get(unsigned char &ch) {
    unsigned char x = getc(fp);
    //if(feof(fp)) return NULL;
    ch = x;
    return *this;
}

unsigned char iqstream::get() {
    unsigned char x = getc(fp);
    if(feof(fp)) return EOF;
    return x;
}

iqstream &iqstream::rewind() {
    qstream::qrewind();
    return *this;
}