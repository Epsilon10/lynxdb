#include "buffer.hh"

#define MIN(a,b) (((a)<(b))?(a):(b))

void Buffer::read(std::vector<uint8_t>& out, size_t size) {
    if (size == 0 || len == 0 || pos >= data.size())
        return;
    size = MIN(size, len - pos);
    out.assign(data.begin() + pos, data.end());
    pos += size;    
}

void Buffer::write(const std::vector<uint8_t>& write_data) {

    // for first write, initialize buffer to size
    if (data.size() == 0) {
        max = data.size();
        data.assign(write_data.begin(), write_data.end());
        return;
    }

    // reposition contents in order to avoid wasting front bytes
    if (pos != 0) {
        data.erase(data.begin(), data.begin() + pos);
        pos = 0;
    }

    // resize buffer data if too small + extra room to avoid constant resizing
    if (write_data.size() + data.size() > max) {
        max = (len + data.size()) * 6 / 5;
        data.resize(max);
    }

   data.insert(data.end(), write_data.begin(), write_data.end());

}

void Buffer::release() { this->Buffer::~Buffer();}