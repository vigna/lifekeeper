# Welcome to `lifekeeper`

## Introduction

`lifekeeper` is a completely trivial program that prints an ASCII `NUL`
character every 30 seconds. This has no effect visually, but if someone is
watching the connection for activity it will see some. People using remote
connections through firewalls might find it useful, as often masquerading
firewalls are configured so to shut down connections that appear not to be
active for some time.

## Usage

The suggested way of using `lifekeeper` is to start it as a background job
in a configuration file read by your shell (e.g., `$HOME/.bash_profile`).
`lifekeeper` exits when its parent does, so you do not need to kill it
explicitly.

For instance, if you use the bash you should add the following lines to `$HOME/.bash_profile`:
```shell
# Is this an interactive shell?
if [ "$PS1" ]; then
  lifekeeper &
fi
```

If you want to be more careful, you should also check whether lifekeeper is installed at all, and whether you are connected via a local ssh (or other remote login protocol):

```shell
which lifekeeper &>/dev/null
RC=$?

if [[ "$PS1" \
      && "$SSH_CLIENT" \
      && $SSH_CLIENT != 127.0.0.1* \
      && "$RC" = "0" ]]; then
  lifekeeper &
fi
```