#include"loader.h"
#include"text/kernel.txt.h"
namespace loader {
std::string load() {
    return std::string(reinterpret_cast<const char*>(text_kernel_txt), text_kernel_txt_len);
}
} // namespace loader