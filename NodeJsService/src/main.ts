// import http = require('http');
// var port = process.env.port || 1337;
// http.createServer(function (req, res) {
//     res.writeHead(200, { 'Content-Type': 'text/plain' });
//     res.end('Hello World\n');
//     res.on("message", (data) => {
//         console.log(data);
//     })
// }).listen(port);
// console.log(`Server Started! Please visit http://127.0.0.1:${port}`);


var net = require('net');
var server = net.createServer();
server.on("connection", function (socket) {
    console.log("远程socket端口：" + socket.remotePort);
    console.log("远程socket地址：" + socket.remoteAddress);
    console.log("本地socket端口：" + socket.localPort);
    console.log("本地socket地址：" + socket.localAddress);

    socket.on("data", function (data) {
        console.log(data.toString());
        console.log("接受到字节量：" + socket.bytesRead);
        socket.write("send byte ... ")
        console.log("发送的字节量：" + socket.bytesWritten);
    })
})

server.listen(1338, function () {
    console.log('服务器已启动！');
});
