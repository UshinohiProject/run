#include <Servo.h> 

// サーボオブジェクトの作成
Servo myservo;

// 使用するピンの定義
// サーボモーターの信号線を接続するピン（PWM出力可能なピン）
const int servoPin = 9;
// スイッチの接続ピン
const int switchPin = 2;

void setup() {
  // サーボモーターを指定したピンに接続
  myservo.attach(servoPin);
  // スイッチのピンを内部プルアップ抵抗付きの入力に設定
  pinMode(switchPin, INPUT_PULLUP);
  
  // 初期状態としてサーボモーターを0度に設定
  myservo.write(0);
}

void loop() {
  // スイッチの状態を読み取る
  int switchState = digitalRead(switchPin);

  if (switchState == HIGH) {
    // スイッチが押されている（HIGH）の場合
    // サーボモーターを0度から正方向に120度に回転
    myservo.write(120);
  } else {
    // スイッチが押されていない（LOW）の場合
    // サーボモーターを元の0度に戻す
    myservo.write(0);    
  }
  
  // サーボの動作を安定させるために少し待機（15ミリ秒）
  delay(15);
}
