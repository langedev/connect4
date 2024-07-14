{
  description = "C Development";

  inputs = {
    nixpkgs.url = "nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
  let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages.${system};
    libs = with pkgs; [
      git
      gnumake
      gcc
      gdb
      # clang_16
      # clang-tools_16
      # lld_16
      # llvmPackages_16.libllvm
    ];
  in {
    devShells.${system}.default = pkgs.mkShell {
      buildInputs = libs;
      LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath libs;
    };
  };
}
