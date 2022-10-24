#include"loader/loader.h"
#include"adder/adder.h"
namespace loader {
int load() {
    return adder::add(1, 2);
}
} // namespace loader