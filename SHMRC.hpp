#pragma once
//#include <sys/types.h>
#include <array>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <sys/shm.h>

// based on: https://github.com/crossa/raspberry-pi-ppm-rc-in

#define NCHANNELS 8

class SHMRC
{
public:
    SHMRC()
    {
        int shmid;
        if ((shmid = shmget(key, sizeof(int*)*NCHANNELS, IPC_CREAT | 0666)) == -1) {
//            return 0x01;
//            On success, a valid shared memory identifier is returned.  On
//            error, -1 is returned, and errno is set to indicate the error.
            std::cerr<< "shmget failed: " << std::strerror(errno) << std::endl;
        }

        void *p;
        if ((p = shmat(shmid, NULL, 0)) == (void*)-1) {
            std::cerr<< "shmat failed: " << std::strerror(errno) << std::endl;
        }
        mem=(int*)p;
    }

    void set(const std::array<float, NCHANNELS> &channels)
    {
        // TODO: copy all at once
        for (int i = 0; i<NCHANNELS; i++)
        {
            *(mem+i) = channels[i];
        }
    }

private:
    static constexpr key_t key=4096;
//    static constexpr int channels = 8;

//    int shmid;
    int *mem;
};
