# Internet-of-Things

## Светофор с arduino nano [traffic lights](https://github.com/Kirilligu/Internet-of-Things/tree/main/traffic%20lights).
#### Проект представляет собой симуляцию работы светофора, управляемого микроконтроллером Arduino nano. Светофор может работать в двух режимах: автоматическом и ручном. В автоматическом режиме он циклически переключает цвета: зеленый (10 с) - мигающий зеленый (2 с) - желтый (1с) - красный (7 с) - желтый (1с) - зеленый (10 с). В ручном режиме можно управлять светофором через командную строку с ПК, задавая включение красного или зеленого света. Перед переключением между цветами через команды происходит 3-секундный переход через желтый цвет. После 60 секунд работы в ручном режиме светофор автоматически возвращается в автоматический режим.
### Для создания светофора понадобится:
- Плата Arduino
- Светодиоды (красный, жёлтый, зелёный)
- Резисторы от 165 Ом (3 шт)
- Соединительные провода
- Макетная плата (Breadboard)
- Компьютер с установленной Arduino IDE
- USB-кабель для подключения Arduino к компьютеру

### Шаги по сборке проекта
1. Подключите светодиоды к плате Arduino через резисторы
2. Подключите светодиоды к соответствующим пинам:
   - Красный — к пину 2
   - Желтый — к пину 3
   - Зеленый — к пину 4
3. Подключите общий провод всех светодиодов к GND на плате Arduino
4. Установите Arduino IDE на компьютер
5. Загрузите код в плату через USB-кабель
6. Откройте Serial Monitor для управления светофором

### Схемы подключения 
![scheme](https://github.com/user-attachments/assets/6e17c10e-c4ff-4f94-a171-aa6da2def8be)
![image](https://github.com/user-attachments/assets/dbd85289-1b3d-4aae-bf41-abf549f75320)

### Видео работы проекта 
https://cloud.mail.ru/public/vg27/Kyrp9uv6E

## Детектор источника света с arduino nano [Light_source_detector](https://github.com/Kirilligu/Internet-of-Things/tree/main/Light_source_detector).
#### Проект представляет собой детектор направления источника освещенности, который использует два фоторезистора для определения разницы в освещенности и индикации направления, в котором находится более яркий источник света (например, окно). Система управляет двумя светодиодами, которые сигнализируют, в какую сторону необходимо повернуть устройство, чтобы источник света оказался прямо перед ним. Когда устройство находится в оптимальном положении, оба светодиода горят постоянно.

### Для создания детектора источника света понадобится:
- Плата Arduino
- 2 фоторезистора
- 2 светодиода
- 2 резистора для светодиодов (4 шт)
- Макетная плата и соединительные провода

### Шаги по сборке проекта
1. Фоторезистор 1 (pht1) подключить к аналоговому пину A0
2. pht2 подключить к аналоговому пину A1
3. LED1 подключить к цифровому пину 9
4. LED2 подключить к цифровому пину 8
5. Установите Arduino IDE на компьютер
6. Загрузите код в плату через USB-кабель


### Схемы подключения 
![Dazzling Jarv](https://github.com/user-attachments/assets/a05cde81-e87d-49dd-837e-4fb0c3ce826d)
![image](https://github.com/user-attachments/assets/9c24c18b-fe2a-4f2f-a6fd-9685373ebe3a)

### Видео работы проекта 
https://cloud.mail.ru/public/YsXo/9wuftQXbf


## Управление светодиодом в зависимости от освещенности с arduino nano [LedPhotoDistributedSerial](https://github.com/Kirilligu/Internet-of-Things/tree/main/LedPhotoDistributedSerial).
#### Этот проект реализует управление светодиодом в зависимости от показаний фоторезистора, используя две Arduino-платы. Одна плата контролирует светодиод, а другая считывает значения освещенности с фоторезистора и передает их на первую плату. Датчик и светодиод подключены к разным микроконтроллерам. Микроконтроллеры не связаны между собой напрямую, только с помощью USB через ПК. Микроконтроллеры просто отрабатывают команды присланные с ПК, решение принимается на ПК.

### Для создания понадобится:
- Плата Arduino (x2)
- Фоторезистор
- Светодиод
- 2 резистора 
- Макетная плата и соединительные провода

### Шаги по сборке проекта
1. Фоторезистор подключить к аналоговому пину A7 (если используете Arduino uno, то нужно поменять порт как на плате, так и в коде, например на A5)
2. Светодиод подключить к цифровому пину 2
3. Установите Arduino IDE на компьютер
4. Загрузите коды в платы через USB-кабель


### Схемы подключения 
![Smooth Waasa-Curcan](https://github.com/user-attachments/assets/4d917338-38a9-40ec-b54d-05e6c2c3fe18)
![image](https://github.com/user-attachments/assets/347defe8-8e0e-41ac-a229-b26cd36dafc3)


### Видео работы проекта 
https://cloud.mail.ru/public/NaiE/nyKNdCcHd


## Управление светодиодом на основе данных с датчика освещенности через MQTT [MQTT](https://github.com/Kirilligu/Internet-of-Things/tree/main/MQTT).
#### Этот проект реализует распределенное управление светодиодом на основе показаний освещенности, считываемых с датчика, используя два микроконтроллера и коммуникацию между ноутбуками через протокол MQTT. Один микроконтроллер считывает данные с фоторезистора, нормирует их и отправляет через MQTT, в то время как второй микроконтроллер управляет светодиодом на основе полученных данных.

### Для создания понадобится:
- Плата Arduino (x2)
- Фоторезистор
- Светодиод
- 2 резистора 
- Макетная плата и соединительные провода
- Ноутбуки (по одному на каждый микроконтроллер)
- Программы для подключения плат между собой

### Шаги по сборке проекта
1. Фоторезистор подключить к аналоговому пину A7 (если используете Arduino uno, то нужно поменять порт как на плате, так и в коде, например на A5)
2. Светодиод подключить к цифровому пину 2
3. Установите Arduino IDE на компьютер
4. Загрузите коды в платы через USB-кабель
5. Запустить программы с MQTT 


### Схемы подключения 
![Smooth Waasa-Curcan](https://github.com/user-attachments/assets/4d917338-38a9-40ec-b54d-05e6c2c3fe18)
![image](https://github.com/user-attachments/assets/347defe8-8e0e-41ac-a229-b26cd36dafc3)


### Видео работы проекта 
https://cloud.mail.ru/public/dcW4/RNegrKx3y


## Управление светодиодом на основе данных с датчика освещенности через MQTT с микроконтроллерами esp8266 [LedPhotoMQTT](https://github.com/Kirilligu/Internet-of-Things/tree/main/LedPhotoMQTT).
#### Этот проект реализует распределенное управление светодиодом на основе показаний освещенности, полученных с датчика, с использованием двух микроконтроллеров ESP8266 и обменом данными через MQTT-протокол. Один микроконтроллер считывает данные с фоторезистора и отправляет их по MQTT, а второй микроконтроллер управляет светодиодом, принимая решения на основе полученных данных.

### Для создания понадобится:
- Платы ESP8266 (x2)
- Фоторезистор
- Светодиод
- 2 резистора 
- Макетная плата и соединительные провода
- Ноутбуки (по одному на каждый микроконтроллер)
- Программы для подключения плат между собой

### Шаги по сборке проекта
1. Фоторезистор подключить к аналоговому пину A0
2. Светодиод подключить к цифровому пину 2 (на esp8266 - D4)
3. Установите Arduino IDE на компьютер
4. Загрузите коды в платы через USB-кабель
5. Подключите обе платы esp8266 к сети Wi-Fi, которая будет использоваться для соединения с MQTT брокером.
6. Запустить программы с MQTT 


### Схемы подключения 
Схема аналогична предыдущим
![Smooth Waasa-Curcan](https://github.com/user-attachments/assets/4d917338-38a9-40ec-b54d-05e6c2c3fe18)
![image](https://github.com/user-attachments/assets/347defe8-8e0e-41ac-a229-b26cd36dafc3)


### Видео работы проекта 
https://cloud.mail.ru/public/Giqg/LJj36gMBB


## ESP_Lamp [ESP_Lamp](https://github.com/Kirilligu/Internet-of-Things/tree/main/ESP_Lamp).
#### Этот проект разработан для создания WiFi-управляемой лампочки на базе ESP (ESP8266 или ESP32). Устройство может подключаться к домашней WiFi-сети, управляться через MQTT и поддерживает Web-интерфейс для настройки. Лампочка оснащена светодиодной индикацией, которая отображает текущий статус подключения и связи с брокером MQTT. Клиент имитирует автоматический сценарий управления по времени суток: лампочка светиться с 20 по 40 секунду каждой минуты. Каждую слудующую минут происходит уменьшение времени свечения на 1 секунду, например с 20 по 39 секунду и так далее. Минимальное время свечения 10 секунд  (c 25 по 35 секунду). Дальше время работы лампочки сбрасывается снова на 20 секунд и идет повторение сценария.

### Для создания понадобится:
- Плата ESP8266
- Светодиод
- Резистор
- Ноутбуки

### Шаги по сборке проекта
1. Установите Arduino IDE на компьютер
2. Загрузите коды в плату через USB-кабель
3. После этого ESP включит точку доступа с такими данными: SSID - WIFI_LAMP , Пароль - WIFILAMP123.
4. После подключения к esp перейдите на 192.168.4.1 и введите данные вашего домашнего интернета и убедитесь что он подключился (индикатор мигает 2 раза, потом пауза)
5. Убедитесь, что подключение к MQTT произошло (индикатор мигает 2 раза, потом пауза)
6. Запустите клиента на python и подпишитесь на топик, введя id лампочки 1
7. Проект готов и работает

### Видео работы проекта 
https://cloud.mail.ru/public/sEAe/Wu9GxW232


## LedMatrix [LedMatrix](https://github.com/Kirilligu/Internet-of-Things/tree/main/LedMatrix).
#### Схема подключения
![image](https://github.com/user-attachments/assets/0dc5abf5-3b5d-40bc-8b76-7f71a77e1fea)
![Smooth Waasa-Curcan (1)](https://github.com/user-attachments/assets/e1d6d286-81da-4005-925c-85a6da73176f)
![image](https://github.com/user-attachments/assets/ddd7eb7a-cea9-4957-b28e-e4a601cf857c)

### Таблица состояний
![image](https://github.com/user-attachments/assets/607af27a-e408-4651-89ef-ed51bf90d38d)


### Для создания понадобится:
- Плата ESP8266
- Светодиод (x4)
- Резистор (x4)
- Ноутбук

### Шаги по сборке проекта
1. Установите Arduino IDE на компьютер
2. Загрузите код в плату через USB-кабель


### Видео работы проекта 
https://cloud.mail.ru/home/IMG_5254.MOV?weblink=hot5%2FbiH7aFHu2


## LedMatrix8x8 [LedMatrix8x8](https://github.com/Kirilligu/Internet-of-Things/tree/main/LedMatrix8x8).
#### Схема подключения
![Smooth Waasa-Curcan (2)](https://github.com/user-attachments/assets/1e021f0d-f556-424a-85fb-412235c0169e)
![image](https://github.com/user-attachments/assets/86815cb7-0583-4703-97b9-a60c9c226515)



### Для создания понадобится:
- Arduino IDE– 8×8 LED matrix
- Резистор (x6)
- Ноутбук

### Шаги по сборке проекта
1. Установите Arduino IDE на компьютер
2. Загрузите код в плату через USB-кабель


### Видео работы проекта 
https://cloud.mail.ru/public/rFFX/cj2xaJrUc


## LedMatrix8x8_registers [LedMatrix8x8_registers](https://github.com/Kirilligu/Internet-of-Things/tree/main/LedMatrix8x8_registers).
#### Схема подключения
![Smooth Waasa-Curcan (2)](https://github.com/user-attachments/assets/1e021f0d-f556-424a-85fb-412235c0169e)
![image](https://github.com/user-attachments/assets/86815cb7-0583-4703-97b9-a60c9c226515)



### Для создания понадобится:
- Arduino IDE– 8×8 LED matrix
- Резистор (x6)
- Ноутбук

### Шаги по сборке проекта
1. Установите Arduino IDE на компьютер
2. Загрузите код в плату через USB-кабель


### Видео работы проекта 
https://cloud.mail.ru/public/Kcou/P6HdtyoUP


## ShiftRegisters [ShiftRegister](https://github.com/Kirilligu/Internet-of-Things/tree/main/ShiftRegister).
#### Схема подключения
![Fantabulous Uusam-Rottis](https://github.com/user-attachments/assets/476be351-3643-4a0c-9d80-a058c8bc05bd)
![image](https://github.com/user-attachments/assets/0497813d-c7d9-42fb-ba33-3ea28390d52e)



### Для создания понадобится:
- Цифровой индикатор KEM-5161BG
- Arduino UNO
- Регистр 74HC595
- Резисторы 220 Oм (8шт)

### Шаги по сборке проекта
1. Установите Arduino IDE на компьютер
2. Загрузите код в плату через USB-кабель


### Видео работы проекта 
https://cloud.mail.ru/public/heXG/sQaWu9XTy


## BounceProcessing [BounceProcessing](https://github.com/Kirilligu/Internet-of-Things/tree/main/BounceProcessing).
####  Это приложение предназначено для подсчёта количества нажатий на кнопку и устранения эффекта дребезга при нажатии
#### Схема подключения
![image](https://github.com/user-attachments/assets/c614c235-6011-4a7f-b9ed-bd1328b0c3ac)


### Для создания понадобится:
- Arduino UNO
- Кнопка
- Резисторы 220 Oм (8шт)
- Провода для подключения

### Шаги по сборке проекта
1. Установите Arduino IDE на компьютер
2. Загрузите код в плату через USB-кабель


### Видео работы проекта 
https://cloud.mail.ru/public/fxYs/oRPjZSPot


## ButtonMatrix [ButtonMatrix](https://github.com/Kirilligu/Internet-of-Things/tree/main/ButtonMatrix).
####  Реализуйте детектирование нажатий пользователя.

0) (3 балла)Реализуйте работу с кнопками используя регистры PIN# и PORT#, что позволит избавиться от внутренних циклов в update_button_state(). Внешний цикл ( for(int irow = 0; irow < NROWS; irow++) ) реализовать с помощью таймеров - для этого настройте таймеры на прерывания каждые N миллисекунд (задается константой) и на каждом прерывании сдвигайте на одну строку ниже, по достижению последней строки, переходим обратно на первую.

1) (2 балла) В serial monitor нужно выводить информацию, только при смене события - нажатие кнопки, которая не была нажата или отпускание кнопки, которая была нажата. Например, если пользователь нажал и держит кнопки 1, 3, 5 и ничего больше  не делает, то выведено будет один раз, что нажаты кнопки 1, 3, 5. Если пользователь нажал и держит кнопки 1, 3, 5 и потом нажал еще кнопку 7, и спустя время отпустил кнопку 3, то выведено будет три сообщения, "нажаты кнопки 1, 3, 5", "нажаты кнопки 1, 3, 5, 7", "нажаты кнопки 1, 5, 7".

2) (2 балла) Нужно вести учет длительности и начала нажатия нажатия каждой из кнопок. Выводите его после того как кнопка была отпущена. Если пользователь нажал и держит кнопки 1, 3, 5 и потом нажал еще кнопку 7, и спустя время отпустил кнопку 3, то выведено будет дополнительное сообщение к предыдущим - "нажаты кнопки 1, 3, 5", "нажаты кнопки 1, 3, 5, 7", "нажаты кнопки 1, 5, 7", "длительность нажатия кнопки 3 - 4123 мс, начало в 12987 мс". Длительность и начало нажатия могут быть полезны в разных сценариях - попробуйте нажать на клавиатуре клавишу и посмотрите, посмотрите что сначала появилась одна буква, а затем уже началось дублирование (после удержания клавиши определенное время).  Время начала нажатия важно, так как старые нажатия можно "забыть" - например при использовании брелка сигнализации машины вам не нужно учитывать какие кнопки Вы нажимали до этого, даже если команда не была завершена.
#### Схема подключения
![image](https://github.com/user-attachments/assets/6fdf027c-e306-4546-b0db-6b928f1ed4f2)

### Шаги по сборке проекта
1. Установите Arduino IDE на компьютер
2. Загрузите код в плату через USB-кабель


### Видео работы проекта 
https://cloud.mail.ru/public/Wa6y/24Jz2JY8L


## H-bridge [H-bridge](https://github.com/Kirilligu/Internet-of-Things/tree/main/H-bridge).
####  Суть задания
Создать схему подключение мотора так чтобы можно было управлять как скоростью так и направлением вращения. Написать функцию для управления мотором. В функцию должно передаваться направление и скорость. Используйте эту функцию в loop чтобы продемонстрировать разные режимы работы мотора.
#### Схема подключения
![Fantastic Turing-Wluff](https://github.com/user-attachments/assets/ce9efa0e-5cda-49a8-a5e1-882a4ae213b6)

### Шаги по сборке проекта
1. Установите Arduino IDE на компьютер
2. Соберите макет
3.  Загрузите код в плату через USB-кабель


### Схема в Tinkercad
https://www.tinkercad.com/things/9i0L8GXz2Nv-fantastic-turing-wluff?sharecode=Wkb57XTvXZ40aVmLFshSoNxD_X27Axj2mIryD59IqYA


## RangeCalibration [RangeCalibration](https://github.com/Kirilligu/Internet-of-Things/tree/main/RangeCalibration).
####  Суть задания
Необходимо разработать систему калибровки инфракрасного дальномера с использованием данных ультразвукового сенсора. Задача включает следующие этапы:

Сбор данных:
С использованием ультразвукового сенсора и инфракрасного датчика собрать данные, которые позволят построить модель зависимости показаний инфракрасного сенсора от реального расстояния.
Программа должна принимать диапазон расстояний для калибровки (например, от 10 до 20 см).
При сборе данных должны быть учтены все значения в пределах диапазона, с пропусками не более 2 см.
Микроконтроллер должен сигнализировать, когда данных достаточно для построения модели (например, мигая светодиодом).
Построение модели:

На компьютере (Python) построить модель зависимости (полином), используя собранные данные.
Для этого можно использовать полиномы различных степеней. Например, для линейной модели — полином первой степени, для более точной модели — полином третьей степени.
Программа на Python должна построить график с точками, которые были собраны с сенсора, и наложить на него модель.
Использование модели:

Функция на микроконтроллере будет преобразовывать данные с инфракрасного сенсора в сантиметры, используя построенную модель.
Программа на Python:

Программа должна собрать данные через Serial (UART), провести расчет и построить графики.
Реализовать калибровку на основе собранных данных.
#### Схема подключения

### Шаги по сборке проекта
1. Установите Arduino IDE на компьютер
2. Соберите макет
3.  Загрузите код в плату через USB-кабель

### Видео работы проекта 
https://cloud.mail.ru/public/eD3R/KBr9NayK5
