#include <VEngine/Core/Logger.h>
#include <memory>

uptr<Log> Log::Instance_ = nullptr;
std::mutex Log::m_;


VENGINE_API uptr<Log> Log::Instance(){
 std::lock_guard<std::mutex> lock(m_);
  if (Instance_ == nullptr){
      Instance_ = std::make_unique<Log>(Log());
  }
  return std::move(Instance_); // since ints a unique_ptr and cannot be copied but moved
}

