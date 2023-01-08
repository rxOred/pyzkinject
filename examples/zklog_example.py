from pyzkinject import zklog

log = zklog.Zklog.get_logger()
log.push_log("pushing to zk logger", zklog.log_level.LOG_LEVEL_DEBUG)
log.push_log("pushing another", zklog.log_level.LOG_LEVEL_ERROR, zklog.log_error_code.LOG_ERROR_INVALID_SECTION)

print(log.pop_log())
print(log.pop_log())
