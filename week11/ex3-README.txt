Вывод первой программы:
Hello
Hello

Вывод второй программы:
Hello
\n
\n

Почему у первой такой вывод?
Оба процесса выведут Hello и \n, потому что оба хранят Hello в буффере и оба добавят \n в буффер после fork.

Почему у второй такой вывод?
После вызова fork программа создает первый дочерний процесс, который наследует буффер от родительского. В нашем случае,
дочерний процесс будет вызван после Hello\n и выведет в терминал \n. Ну и второй \n от основного процесса.
