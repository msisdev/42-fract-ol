# 42-starter

![norminette](https://github.com/msisdev/42-starter/workflows/norm/badge.svg)




## What is this?

`42-starter` is...
- a C project starter
- with an opinionated folder structure
- for ecole 42

that supports automated tasks that run whenever you push a commit such as...
- [norminette](https://github.com/42school/norminette) test
- build project
- run custom tests

> [!NOTE]
> These features depend on [Github Actions](https://github.com/features/actions) and require your repo to be placed in Github. It is free and available in both public and private repo.

> [!NOTE]
> `42-starter` is opinionated and requires you to use the same folder structure and `Makefile` because the Github Action workflows depend on them.




## Quickstart

Press the `Use this template` button above. As a result, you will a create another repository that has the same files with this repo.




## Get Started
```
ex00
├── Makefile
├── app
│   └── main.c
├── include
│   ├── ft_42.h
│   ├── global.h
│   └── types.h
├── lib
│   └── ft_42.c
├── src
│   └── global.c
├── test
│   ├── fail_test
│   │   └── main.c
│   └── success_test
│       └── main.c
├── test_include
│   └── test.h
├── test_src
│   └── assert.c
└── tester.sh
```
- `app`: sources related with main functions.
- `include`: a place where all headers go in.
- `lib`: sources related with `lib.a`.
- `src`: sources for main logic
- `test`: a place where individual test programs go in.
- `test_include`: common headers for all test related srcs
- `test_src`: common srcs for each test programs
- `tester.sh`: a script that does same with test workflow.




## Reference

[GitHub Action norminette](https://github.com/alexandregv/norminette-action?tab=readme-ov-file) by alexandregv
