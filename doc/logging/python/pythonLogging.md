# Overview
This document describes how the Logging utilitiy works in Python

# Logging Structure
In Python, the Logger is an object that can be interacted with to generate a variety of log messages. The Logger provides the following functions:
- debug()
- info()
- warning()
- error()
- exception()
- critical()

Each of those functions are then used to generate a Log Record object which contains the following information:
- message
- level
- created
- thread
- ...

The Logger is comprised of several layers that each define how data is logged. Inside an individual logger are the following:
- Level
    - Defines what the lowest severity Log Record that can be logged by this instance of Logger. All Log Records with a lower priority will be dropped
- Filters
    - Provides the criteria to identify what Log Records should be dropped by the Logger.
        - ie if the Log Record contains a specfic string in the message then it will be dropped
- Formatters
    -Defines what the log output looks like
- Handlers
    - Object that actually performs the logging to the desired destination
        -ie to STDOUT, or to a File
    - Each handler can also have its own Level, Filter and Formatter

Logging in Python can actually be made of a heiarchy of Loggers. If any message is filtered out by a Logger's handler then it will still propagate to the parent. However, if it is filtered out by either the child Loggers Level or Filter then it will not propagate up to the parent.

As a best practice, the Level and Filter should only be specified in the root Logger to minimize complexity and reduce the likelihood of configuration errors.