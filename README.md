### Help

- Framework in macos(M1): /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks
- Compile :

```zsh
  $ gcc src/main.c -I include -I lib/libft -I lib/mlx  -L lib/libft -lft -L lib/mlx -lmlx -framework OpenGL -framework Appkit
```

### FIXME

1.  src or srcs? include or includes ..... etc
