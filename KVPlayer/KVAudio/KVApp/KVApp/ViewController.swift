//
//  ViewController.swift
//  KVApp
//
//  Created by Mike Green on 2020/7/24.
//  Copyright © 2020 KV. All rights reserved.
//

import Cocoa

class ViewController: NSViewController {

    // 录制状态
    var recordStatus: Bool = false;
    // 创建一个按钮
    let btn = NSButton.init()
    // 初始化线程
    var thread: Thread?
    
    override func viewDidLoad() {
        // 窗口加载后进行的操作
        super.viewDidLoad()
        // 设置窗口大小
        self.view.setFrameSize(NSSize(width: 640, height: 360))
        
        // 设置按钮文字
        btn.title = "Start REC~";
        // 设置按钮位置
        btn.frame = NSRect(x: 640/2-60, y: 360/2-15, width: 80, height: 30)
        // 设置圆角
        btn.bezelStyle = .rounded
        // 设置按钮类型
        btn.setButtonType(.pushOnPushOff)
        // 设置按钮实践
        btn.target = self
        btn.action = #selector(myfunc)
        // 将按钮加入到窗体中
        self.view.addSubview(btn)
    }
    
    // 按钮回调函数
    @objc
    func myfunc(){
        print("Hello KVAudio~")
        // 录制状态切换
        self.recordStatus = !self.recordStatus;
        if recordStatus {
            thread = Thread.init(target: self, selector: #selector(self.recAudio), object: nil)
            thread?.start();
            self.btn.title = "Stop REC~"
        }else{
            set_status(0)
            self.btn.title = "Start REC~"
        }
        // 调用C函数
        //record_audio()
    }
    
    @objc func recAudio(){
        record_audio()
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }


}

