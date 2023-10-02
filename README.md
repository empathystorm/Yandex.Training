# Тренировки по алгоритмам
Мои решения задач курса ["Тренировки по алгоритмам"](https://yandex.ru/yaintern/algorithm-training_1) от Яндекса на языках **C++** и **Python**

## Часть [1.0](https://yandex.ru/yaintern/algorithm-training_1) (2021)
| № | Лекция | Решения 1.0 |
| :-: | - | - |
| 1 | [Сложность, тестирование, особые случаи](https://youtu.be/QLhqYNsPIVo) | [10/10](/training_1.0/1_complexity/) C++ |
| 2 | [Линейный поиск](https://youtu.be/SKwB41FrGgU) | [10/10](/training_1.0/2_linear%20search/) C++ |
| 3 | [Множества](https://youtu.be/PUpmV2ieIHA) | [10/10](/training_1.0/3_set/) C++ |
| 4 | [Словари и сортировка подсчётом](https://youtu.be/Nb5mW1yWVSs) | [10/10](/training_1.0/4_dictionaries/) C++ |
| 5 | [Префиксные суммы и два указателя](https://youtu.be/de28y8Dcvkg) | [10/10](/training_1.0/5_prefix%20sum) C++ |
| 6 | [Бинарный поиск](https://youtu.be/YENpZexHfuk) | [11/11](/training_1.0/6_binary%20search) Python |
| 7 | [Сортировка событий](https://youtu.be/hGixDBO-p6Q) | [2/10](/training_1.0/7_event%20sorting) Python |
| 8 | [Деревья](https://youtu.be/lEJzqHgyels) | [3/10](/training_1.0/8_trees) C++ |

## Другие контесты
| Контест | Решения |
| - | - |
| [Тренировочный контест - бэкенд](https://contest.yandex.ru/contest/50668/) | [2/5](/training_backend) Python/C++ |

## Трудности разработки
#### Проблема с типом int в [C++](https://www.youtube.com/shorts/yV0heEXVKjY) *(встречается в занятиях 2: G,H / 4: E,F / 5: D,G)*
<ins>Проблема:</ins> Ошибка WA на больших количествах тестах: 10-50\
<ins>Причина:</ins> В данных заданиях используются большие значения, которые превосходят тип int в C++, т.е. больше $2*10^9$\
<ins>Решение:</ins> Следует использовать long\
<ins>Совет:</ins> Смотрите внимательно на ограничения по значениям в задании. Также учитывайте особенности C++, например, дан код:
```C++
long count = 0;
int rangeLen = r - l;
count += (rangeLen - 1) * (rangeLen - 2) * 3;
```
В данном случае `rangeLen` не может быть больше $2*10^9$, а вот выражение `(rangeLen - 1) * (rangeLen - 2) * 3` вполне может, и, не смотря на то, что слева переменная типа `long`, выражение справа всё ещё `int` и, в результате, к `count` прибавиться переполненное значение. Поэтому в данном случае `rangeLen` должен быть `long`.
