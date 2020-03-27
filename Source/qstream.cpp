//
// Created by Quvi on 3/22/2020.
//

#include "qstream.h"

qstream::qstream(const char *loc, const char *open_mode) {
    if (loc != nullptr) {
        this->loc = new char[strlen(loc) + 1];
        strcpy(this->loc, loc);
    }
    this->open_mode = new char[strlen(open_mode) + 1];
    strcpy(this->open_mode, open_mode);
    fp = fopen(loc, open_mode);
}

qstream::qstream(qstream &&source) {
    fp = source.fp;
    loc = source.loc;
    open_mode = source.open_mode;
    source.fp = nullptr;
    source.loc = nullptr;
    source.open_mode = nullptr;
}

qstream &qstream::operator=(qstream &&rhs) {
    fclose(fp);
    delete[] loc;
    delete[] open_mode;
    fp = rhs.fp;
    loc = rhs.loc;
    open_mode = rhs.open_mode;
    rhs.fp = nullptr;
    rhs.loc = nullptr;
    rhs.open_mode = nullptr;
    return *this;
}

void qstream::close() {
    fclose(fp);
    delete[] loc;
    delete[] open_mode;
    fp = nullptr;
    loc = nullptr;
    open_mode = nullptr;
}

qstream::~qstream() {
    fclose(fp);
    delete[] loc;
    delete[] open_mode;
}

int qstream::tell() const {
    return ftell(fp);
}

void qstream::seek(int offset, int direction) {
    fseek(fp, offset, direction);
}

void qstream::open(const char *loc, const char *open_mode) {
    if(fp) close();
    fp = fopen(loc, open_mode);
    this->loc = new char[strlen(loc) + 1];
    strcpy(this->loc, loc);
    this->open_mode = new char[strlen(open_mode) + 1];
    strcpy(this->open_mode, open_mode);
}

void qstream::qrewind() {
    rewind(fp);
}
