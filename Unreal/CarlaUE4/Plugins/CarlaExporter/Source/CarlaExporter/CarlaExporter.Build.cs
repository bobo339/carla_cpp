// Copyright (c) 2019 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

using UnrealBuildTool;
// CarlaExporter类继承自ModuleRules，用于定义名为CarlaExporter模块的构建规则
// 它接收ReadOnlyTargetRules类型的Target参数，以便依据不同目标平台等具体情况来精准配置模块构建的相关细节
public class CarlaExporter : ModuleRules
{ // 设置预编译头（PCH，Precompiled Header）的使用模式为UseExplicitOrSharedPCHs
  // 意味着可以选择显式使用或者共享预编译头文件，具体方式会根据项目中的其他配置以及实际需求而定
  public CarlaExporter(ReadOnlyTargetRules Target) : base(Target)
  {     // 设置预编译头（PCH，Precompiled Header）的使用模式为UseExplicitOrSharedPCHs
        // 意味着可以选择显式使用或者共享预编译头文件，具体方式会根据项目中的其他配置以及实际需求而定
    PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        // 以下部分用于添加该模块对外公开的头文件包含路径
        // 其他模块若要使用CarlaExporter模块中公开的接口、结构体等内容时，
        // 往往需要包含此处添加路径下的头文件。以下是一些示例路径添加，可按需修改或扩充。
    PublicIncludePaths.AddRange(
      new string[] {
        // 假设CarlaExporter模块有一些公共的工具头文件放在此文件夹下，供外部使用
                Path.Combine(ModuleDirectory, "Public"),
                // 如果有一些通用的第三方库头文件需要对外公开引用，也添加在这里
                Path.Combine(ModuleDirectory, "ThirdParty", "SomeLib", "Include")
      }
      );


 // 这部分用于添加该模块内部使用的头文件包含路径
        // 外部模块通常无法直接访问这些路径下的头文件内容，它们仅供CarlaExporter模块内部实现功能使用。
        // 下面是一些可能的示例路径添加，同样可按实际情况进行调整。
        PrivateIncludePaths.AddRange(
            new string[] {
                // 模块内部实现逻辑相关的头文件所在文件夹
                Path.Combine(ModuleDirectory, "Private"),
                // 若模块依赖某个特定功能的内部库，其头文件路径可添加在此
                Path.Combine(ModuleDirectory, "ThirdParty", "AnotherLib", "PrivateInclude")
            }
        );

        // 定义CarlaExporter模块在编译时需要静态链接的公共依赖模块
        // 当前已列出了依赖Core模块，Core模块提供了Unreal Engine项目的基础核心功能，是很多模块的基础依赖。
        // 这里再添加一些可能的其他公共依赖模块示例，比如如果模块涉及网络通信相关功能，可能依赖网络模块等。
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                // 若模块需要进行网络操作，添加网络相关模块依赖
                "Networking",
                // 如果有与渲染相关的公开接口供外部使用，可添加渲染模块依赖
                "Renderer"
                //... add other public dependencies that you statically link with here...
            }
        );

        // 这里列出了CarlaExporter模块内部编译时需要静态链接的私有依赖模块
        // 这些模块主要是为了满足CarlaExporter模块自身内部实现的需要，外部模块一般不直接关注它们。
        // 例如Projects模块可能与项目相关配置等功能有关，InputCore涉及输入相关功能等，以下保持原有基础并添加注释说明。
        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Projects",    // 与项目配置等相关功能的模块依赖
                "InputCore",   // 用于处理输入相关操作的模块依赖
                "UnrealEd",    // 与虚幻编辑器相关功能的模块依赖
                "LevelEditor", // 涉及关卡编辑相关操作的模块依赖
                "CoreUObject", // 提供核心的UObject系统支持，对很多功能实现很
                "Engine", // 提供了整个游戏引擎的核心运行逻辑等功能，是模块运行的基础依赖，内部很多功能实现可能调用引擎相关接口
                "Slate",       // 用于构建用户界面相关元素，若模块有自定义的UI界面来辅助导出功能（如选择导出选项等），会依赖此模块
                "SlateCore",   // Slate模块的核心支持部分，和Slate模块配合使用来完善UI相关功能实现
                "Physx",       // 若模块涉及到物理模拟相关的数据导出或者和物理相关的交互功能，需要依赖此模块
                "EditorStyle", // 用于获取编辑器相关的样式资源，使得模块在编辑器中的界面显示等符合整体风格，若有UI部分会用到
                //... add other private dependencies that you statically link with here...
            }
        );

        // 用于指定该模块在运行时动态加载的其他模块
        // 例如，如果模块有一些可选的功能模块，只有在特定条件下才需要加载运行，可在这里添加
        // 目前添加一个示例，比如有一个高级导出功能模块，只有用户选择高级导出模式时才动态加载并启用
        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
                "AdvancedExportModule"
                //... add any modules that your module loads dynamically here...
            }
        );
    }
}
