## Инвертирование битов

В данном репозитории приведена реализация инвертирования определенных битов, выбираемых из каждого байта.

## Реализации

Данная программа позволяет инвертировать биты в четырех разных сценариях:
- Инвертирование всех битов
- Инвертирование битов с определенного бита до так же определенного 
- Инвертация по маске(одной для всех байт)
- Инваертация по макскам(маски могут быть различны(если их не хватает, то берется первая маска))

## Компиляция и исполнение

```sh
g++ -std=c++11  main.cpp -o main; ./main
```

