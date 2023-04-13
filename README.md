# Smart-Engraving
How to use?

Before powering the Arduino, put the engraver on a flat surface (for this mpu 6050 to calibrate itself properly) you can tell by the leds on it that the calibration process is finished.

After the LED turns off, it means it is ready to use, you can adjust the speed by using the speed adjustment buttons.

When you put the device on a flat surface, the motor will stop. It will work again when you remove the device again. (It will work with the speed you set at the end. Be careful :) )

Thanks to the gyro module inside, if it detects skidding during use, it will cut off the power to the engine. It will work again when you press one of the speed adjustment buttons. (It will work with the speed you set at the end. Be careful :) )

Expandable features:

Since I couldn't fit more parts, I used an absit mosfet while driving the engine, this is not very healthy. It will be more accurate to use a motor driver or to drive the mosfet in a better way.

Soft start can be added by software for the soft start of the motor.

-----------------------------------------------------------------------

Nasıl kullanılır?

Arduino'ya güç vermeden önce gravür makinesini düz bir zemine koyun ( bu mpu 6050 nini kendini düzgün kalibre etmesi için) kalibre işleminin bittiğini üzerindeki ledelrden anlayabilirsiniz.

Led söndükten sonra kullanıma hazır demektir, devir ayarlama butonlarını kullanarak devir ayarlayabilirsiniz.

Cihazı düzbir zemine koyduğunuzda motor duracaktır. Cihazı yeniden kaldırdırdığınızda yenden çalışacaktır. (Enson ayarladığınız hız derecesiyle çalışacaktır. dikkatli olun :)  )

İçindeki gyro modülü sayesinde kullanım sırasında savrulma algılarsa motora giden gücü kesecektir. Devir ayar butonlarından birine bastığınızda tekrar çalışacak. (Enson ayarladığınız hız derecesiyle çalışacaktır. dikkatli olun :)  )

Geliştirilebilir yönleri: 

Ben daha fazla parça sığdıramayacağım için motoru sürerken absit bir mosfet kullandım, bu çok sağlıklı değil. Motor sürücü kullanmak yada mosfeti daha iyi birşekilde sürmek daha doğru olacaktır. 

Motorun yumşak çalışması için yazılımla soft start eklenebilir.
