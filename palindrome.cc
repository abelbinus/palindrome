#include <nan.h>

using namespace v8;

void IsPalindrome(const FunctionCallbackInfo<Value>& info) {
  String::Utf8Value sentence(info[0]->ToString());
  std::string str = std::string(*sentence);
  int len = str.length();
  int half = len / 2;
  int start = 0;
  int end = len - 1;
  int space = 32;
  bool isPal = true;

  while (half > 0 && isPal) {
    bool startSpace = str.at(start) == space;
    bool endSpace = str.at(end) == space;

    if (str.at(start) == str.at(end)) {
      start++;
      end--;
    } else if (startSpace || endSpace) {
      startSpace && start++;
      endSpace && end--;
    } else {
      isPal = false;
    }

    half--;
  }

  info.GetReturnValue().Set(isPal);
}

void Init(Local<Object> exports, Local<Object> module) {
  NODE_SET_METHOD(module, "exports", IsPalindrome);
}

NODE_MODULE(addon, Init)