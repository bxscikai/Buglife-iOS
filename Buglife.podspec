Pod::Spec.new do |s|
  s.name                  = "Buglife"
  s.version               = "0.1.0"
  s.summary               = "Awesome bug reporting 😎"
  s.description           = "Report bugs, annotate screenshots, and collect logs from within your iOS app!"
  s.homepage              = "http://www.buglife.com"
  s.license               = { "type" => "Commercial", "text" => "See http://www.buglife.com/terms"}
  s.author                = { "Buglife" => "support@buglife.com" }
  s.source                = { "git" => "https://github.com/Buglife/Buglife-iOS.git" }
  s.platform              = :ios, '7.0'
  s.preserve_paths        = [ "Buglife.framework/*" ]
  s.public_header_files   = "Buglife.framework/Versions/A/Headers/*.{h}"
  s.vendored_frameworks   = "Buglife.framework"
end
