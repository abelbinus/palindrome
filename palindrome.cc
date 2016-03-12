#include <nan.h>

using namespace v8;

void IsPalindrome(const FunctionCallbackInfo<Value>& info) {
  Local<v8::String> s = info[0]->ToString();
  String::Utf8Value arg0(s);
  char* str = *arg0;
  int len = s->Length();
  int half = len / 2;
  int start = 0;
  int end = len - 1;
  int space = 32;
  bool isPal = true;

  while (half > 0 && isPal) {
    bool startSpace = str[start] == space;
    bool endSpace = str[end] == space;

    if (str[start] == str[end]) {
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