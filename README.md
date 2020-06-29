utf8_diff
==============

This script show differences of utf-8 character.
これはutf-8の文字列を比較するためのスクリプトだ．

For example,
例えばこんな感じで使う

```
./utf8_diff "あいう" "あきう"
あ/い/き/E3 81 8D/E3 81 84/う
```

Different points are displayed as
表示方法はこんな感じ

```
/<left char>/<right char>/<left char hex>/<right char hex>/
```

Very simple, left, right, left verbose and right verbose.
とてもシンプルで，左の文字列の文字，右の文字列の文字，そしてそれぞれのHexが表示される．

Motivation
-------

I have trouble of zenkaku hypen.
See my repository [FBVVWB](https://github.com/GuiltyCat/fbvvwb).
You will find strange `sed`.

全角のハイフンでとても困ったことがあった．
詳しくは[FBVVWB](https://github.com/GuiltyCat/fbvvwb)を見て欲しいが，
勝手に全角ハイフンが，すぐ近くの別の文字(これもハイフン表示される)に変えられたのだ．
これがコンソールだと分からない．まったく同じ長さ，太さのハイフンだったのだ．
