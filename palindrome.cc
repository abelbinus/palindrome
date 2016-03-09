#include <nan.h>

void isPalindrome(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  v8::String::Utf8Value sentence(info[0]->ToString());
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
      if (startSpace) {
        end++;
      }
      if (endSpace) {
        start--;
      }
    } else {
      isPal = false;
    }

    half--;
  }

  info.GetReturnValue().Set(isPal);
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("isPalindrome").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(isPalindrome)->GetFunction());
}

NODE_MODULE(isPalindrome, Init)
