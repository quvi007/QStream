//
// Created by Quvi on 3/22/2020.
//

#ifndef PRACTICECPP_QSTREAM_H
#define PRACTICECPP_QSTREAM_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BUILDING_QSTREAM_DLL
#define QSTREAM_DLL __declspec(dllexport)
#else
#define QSTREAM_DLL __declspec(dllimport)
#endif

#ifdef __cplusplus
}
#endif


#include <iostream>
#include <cstdio>
#include <cstring>

class QSTREAM_DLL qstream {
protected:
    FILE *fp;
    char *loc;
    char *open_mode;

    virtual void abstract() = 0;

    int tell() const;

    void seek(int, int);

    void qrewind();
public:
    qstream(const char *, const char *);

    qstream(qstream &&);

    virtual qstream &operator=(qstream &&);

    void open(const char *, const char *);

    virtual void close();

    ~qstream();
};

class QSTREAM_DLL iqstream : public qstream {
    void abstract() override {}

public:
    iqstream();

    iqstream(const char *, const char * = "rb");

    iqstream(iqstream &&);

    iqstream &operator=(iqstream &&);

    iqstream &operator>>(int &);

    iqstream &read(char *, int);

    iqstream &get(char &);

    iqstream &get(unsigned char &);

    unsigned char get();

    int tellg() const;

    void seekg(int, int = SEEK_SET);

    void close() override;

    iqstream &rewind();
};

class QSTREAM_DLL oqstream : public qstream {
    void abstract() override {}
public:
    oqstream();

    oqstream(const char *, const char * = "wb");

    oqstream(oqstream &&);

    oqstream &operator=(oqstream && );

    oqstream &operator<<(const char *);

    oqstream &write(const char *, int);

    oqstream &put(const unsigned char);

    int tellp() const;

    void seekp(int, int = SEEK_SET);

    void close() override;

    oqstream &rewind();
};

#endif //PRACTICECPP_QSTREAM_H
