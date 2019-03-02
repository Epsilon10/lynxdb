#pragma once
#include "db.hh"
#include <vector>

class Buffer {
    private:
        size_t pos, max, len;
        std::vector<uint8_t> data;

    public:
       explicit Buffer() : pos(0), max(0), len(0) {} 
       void read(std::vector<uint8_t>& out, size_t size);
       void write(const std::vector<uint8_t>& write_data);
       void release(); 
};