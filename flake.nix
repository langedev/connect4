{
  description = "C Development";

  inputs = {
    nixpkgs.url = "nixpkgs/nixos-unstable";
    mini-compile-commands = { 
      url = "github:danielbarter/mini_compile_commands";
      flake = false;
    };
  };

  outputs = { self, nixpkgs, mini-compile-commands }:
  let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages.${system};
    libs = with pkgs; [
      git
      gnumake
      gcc
      gdb
      clang_16
      clang-tools_16
      lld_16
      llvmPackages_16.libllvm

      cmake
      gtest
    ];
  in {
    devShells.${system}.default = 
    with import nixpkgs { system = "${system}"; };
    let mcc-env = (callPackage mini-compile-commands {}).wrap stdenv;
    in (pkgs.mkShell.override {stdenv = mcc-env;}) {
      buildInputs = libs;
      LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath libs;
    };
  };
}
