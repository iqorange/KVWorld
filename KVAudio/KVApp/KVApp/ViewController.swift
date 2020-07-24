//
//  ViewController.swift
//  KVApp
//
//  Created by Mike Green on 2020/7/24.
//  Copyright © 2020 KV. All rights reserved.
//

import Cocoa

class ViewController: NSViewController {

    override func viewDidLoad() {
        // 窗口加载后进行的操作
        super.viewDidLoad()
        // 设置窗口大小
        self.view.setFrameSize(NSSize(width: 640, height: 360))
        // 创建一个按钮
        let btn = NSButton.init()
        // 设置按钮文字
        btn.title = "KV";
        // 设置按钮位置
        btn.frame = NSRect(x: 640/2-40, y: 360/2-15, width: 80, height: 30)
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
        // 调用C函数
        test()
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }


}

