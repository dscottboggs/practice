# I was really confused by this challenge, until I realized that the prompt was
# to create a non-idempotent manifest. While puppet can do this task, it wasn't
# designed for it.

$base_dir = '/var/save/puppet_move_3'

file { "$base_dir/files":
    ensure => directory,
}
file { "$base_dir/files/text":
    ensure => directory,
}
file { "$base_dir/files/code":
    ensure => directory,
}
file { "$base_dir/files/script":
    ensure => directory,
}
file { "$base_dir/files/other":
    ensure => directory,
}

# == Define: text_file
#
exec { 'Move text files.':
    command => "bash -c 'mv -t $base_dir/files/text $base_dir/old/*.txt'",
    path => '/usr/bin:/usr/sbin:/bin:/usr/local/bin'
}
exec { 'Move script files':
    command => "bash -c 'mv -t $base_dir/files/script $base_dir/old/*.{pp,py,sh}'",
    path => '/usr/bin:/usr/sbin:/bin:/usr/local/bin'
}
exec { 'Move code files':
    command => "bash -c 'mv -t $base_dir/files/code $base_dir/old/*.{c,cpp,cs,java}'",
    path => '/usr/bin:/usr/sbin:/bin:/usr/local/bin'
}
exec { 'Move other files':
    command => "bash -c 'mv -t $base_dir/files/other $base_dir/old/*'",
    path => '/usr/bin:/usr/sbin:/bin:/usr/local/bin'
}
