```shell
npm init
npm i -D ts-node
npm i -D @types/node
npm i -D typescript
npm i -D tslib
npm i -D tslib

```

ts-node不支持esm語法.默認只支持commandjs語法.

tsconfig配置:
```json
{
"compilerOptions": {
	"esModuleInterop": true
	}
}
```

```shell
ts-node ./main.ts
```

即可.