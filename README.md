# WinAPI_keyboard

https://stackoverflow.com/questions/18001317/receiving-keypresses-while-in-background
```
Later edit: if the window is out of focus, it can't process WM_KEYDOWN messages 
even if WM_KILLFOCUS is ignored. Therefore you need to check regularly and separately for GetAsyncKeyState().
```
