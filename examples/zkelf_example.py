from pyzkinject import zkelf, zklog

log = zklog.Zklog.get_logger()
log.push_log("parsing elf binary", zklog.log_level.LOG_LEVEL_DEBUG)
e = zkelf.load_elf_from_file("./test/bash", log)
print("map size is ", e.get_map_size())
print("elf class is", e.get_elf_class())
