// Описывает данные для передачи файла
struct FileChunk
{
    1: required string fileName;
    2: required binary data;
    3: required bool isExecutable;
    4: required i64 shippingCounter;
    5: optional string fileFormat;
    6: optional binary hash
}

// Содержит описание задачи и все 
// данные, необходимые клиенту для её выполнения
struct Task
{
    1: required string taskName;
    2: required string taskDescription;
    3: required list<FileChunk> files;
    4: required string cmdToExec;
    5: optional string otherData;
    6: optional i64 estimatedLeadTime
}

// Описывает данные клиента
struct ClientData
{
    1: required string OS;
    2: required string osVersions;
    3: required string CPU;
    4: required i32 timeZone;
    5: required i64 clientId;
    6: optional string language
}

service FileReceiver
{
    void ping(),
    FileChunk GetFile(1: string fileName),
    Task GetTask(1: ClientData data),
    bool SendResult(1: FileChunk result)
}




