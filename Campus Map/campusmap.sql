-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Mar 28, 2025 at 01:24 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.0.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `campusmap`
--

-- --------------------------------------------------------

--
-- Table structure for table `building`
--

CREATE TABLE `building` (
  `building_id` int(11) NOT NULL,
  `building_name` varchar(255) NOT NULL,
  `location` varchar(10) NOT NULL,
  `number_of_floors` int(11) DEFAULT 1
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `building`
--

INSERT INTO `building` (`building_id`, `building_name`, `location`, `number_of_floors`) VALUES
(1, 'Teaching Complex 2', 'B1, C1, D1', 1),
(2, 'Campus IT Services', 'F3, G3', 1),
(3, 'Faculty of Law', 'I2, J2', 1),
(4, 'Teaching Complex 1', 'A3, A4, B3', 1),
(5, 'Faculty of Medicine', 'B6, C6, D6', 1),
(6, 'Faculty of Social Sciences', 'H7, H8, I7', 1),
(7, 'Faculty of Humanities', 'F10, G10', 1),
(8, 'Faculty of Science and Technology', 'A10, A9, A', 1);

-- --------------------------------------------------------

--
-- Table structure for table `classroom`
--

CREATE TABLE `classroom` (
  `classroom_id` int(11) NOT NULL,
  `building_id` int(11) NOT NULL,
  `room_code` varchar(10) NOT NULL,
  `capacity` int(11) NOT NULL,
  `is_available` tinyint(1) DEFAULT 1
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `classroom`
--

INSERT INTO `classroom` (`classroom_id`, `building_id`, `room_code`, `capacity`, `is_available`) VALUES
(1, 1, 'B1', 30, 1),
(2, 1, 'C1', 30, 1),
(3, 1, 'D1', 30, 1),
(4, 1, 'E1', 30, 1),
(5, 1, 'F1', 30, 1),
(6, 1, 'G1', 30, 1),
(7, 2, 'F3', 20, 1),
(8, 2, 'G3', 20, 1),
(9, 3, 'I2', 40, 1),
(10, 3, 'J2', 40, 1),
(11, 4, 'A3', 35, 1),
(12, 4, 'A4', 35, 1),
(13, 4, 'B3', 35, 1),
(14, 4, 'B4', 35, 1),
(15, 4, 'C3', 35, 1),
(16, 4, 'C4', 35, 1),
(17, 4, 'D3', 35, 1),
(18, 4, 'D4', 35, 1),
(19, 5, 'B6', 50, 1),
(20, 5, 'C6', 50, 1),
(21, 5, 'D6', 50, 1),
(22, 5, 'E6', 50, 1),
(23, 6, 'H7', 60, 1),
(24, 6, 'H8', 60, 1),
(25, 6, 'I7', 60, 1),
(26, 6, 'I8', 60, 1),
(27, 6, 'J7', 60, 1),
(28, 6, 'J8', 60, 1),
(29, 7, 'F10', 25, 1),
(30, 7, 'G10', 25, 1),
(31, 8, 'A10', 45, 1),
(32, 8, 'A9', 45, 1),
(33, 8, 'A8', 45, 1),
(34, 8, 'B10', 45, 1),
(35, 8, 'B9', 45, 1),
(36, 8, 'B8', 45, 1),
(37, 8, 'C10', 45, 1),
(38, 8, 'C9', 45, 1),
(39, 8, 'C8', 45, 1),
(40, 8, 'D10', 45, 1),
(41, 8, 'D9', 45, 1),
(42, 8, 'D8', 45, 1);

-- --------------------------------------------------------

--
-- Table structure for table `favorite_routes`
--

CREATE TABLE `favorite_routes` (
  `id` int(11) NOT NULL,
  `start_location` varchar(10) NOT NULL,
  `end_location` varchar(10) NOT NULL,
  `created_at` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `favorite_routes`
--

INSERT INTO `favorite_routes` (`id`, `start_location`, `end_location`, `created_at`) VALUES
(1, 'A1', 'G5', '2025-03-27 23:11:34'),
(2, 'a1', 'j10', '2025-03-27 23:13:13'),
(3, 'C2', 'G5', '2025-03-27 23:18:58'),
(4, 'E3', 'H6', '2025-03-27 23:23:13'),
(5, 'A1', 'G4', '2025-03-27 23:38:47'),
(6, 'A1', 'F5', '2025-03-27 23:56:56'),
(7, 'E4', 'H5', '2025-03-28 00:17:25'),
(8, 'B2', 'F5', '2025-03-28 00:19:42');

-- --------------------------------------------------------

--
-- Table structure for table `user_activity`
--

CREATE TABLE `user_activity` (
  `id` int(11) NOT NULL,
  `action_type` enum('path_found','classroom_added','path_saved','path_loaded') NOT NULL,
  `description` text NOT NULL,
  `created_at` timestamp NOT NULL DEFAULT current_timestamp(),
  `user_ip` varchar(45) DEFAULT NULL,
  `user_agent` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `user_activity`
--

INSERT INTO `user_activity` (`id`, `action_type`, `description`, `created_at`, `user_ip`, `user_agent`) VALUES
(5, 'path_found', 'A1 -> A2 -> B2 -> C2 -> D2 -> E2 -> F2 -> G2 -> H2 -> H3 -> H4 -> H5', '2025-03-28 00:09:41', NULL, NULL),
(6, 'path_found', 'C5 -> D5 -> E5 -> F5 -> G5 -> H5 -> I5 -> J5', '2025-03-28 00:11:07', NULL, NULL),
(7, 'path_found', 'A2 -> B2 -> C2 -> D2 -> E2 -> E3 -> E4 -> F4 -> F5', '2025-03-28 00:13:26', NULL, NULL),
(8, 'path_found', 'A1 -> A2 -> B2 -> C2', '2025-03-28 00:17:12', '::1', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36'),
(9, 'path_saved', 'Saved: E4 to H5', '2025-03-28 00:17:26', '::1', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36'),
(10, 'path_found', 'B2 -> C2 -> D2 -> E2 -> E3 -> E4 -> F4 -> F5', '2025-03-28 00:19:40', '::1', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36'),
(11, 'path_saved', 'Saved: B2 to F5', '2025-03-28 00:19:43', '::1', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36'),
(12, 'path_found', 'B2 -> C2 -> D2 -> E2 -> E3 -> E4 -> F4 -> F5', '2025-03-28 00:19:46', '::1', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36'),
(13, 'path_loaded', 'Loaded: B2 to F5', '2025-03-28 00:19:46', '::1', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36'),
(14, 'path_loaded', 'Loaded: A1 to F5', '2025-03-28 00:19:47', '::1', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36'),
(15, 'path_found', 'A1 -> A2 -> B2 -> C2 -> D2 -> E2 -> E3 -> E4 -> F4 -> F5', '2025-03-28 00:19:47', '::1', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36'),
(16, 'path_found', 'C2 -> D2 -> E2 -> E3 -> E4 -> F4 -> G4 -> G5', '2025-03-28 00:19:48', '::1', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36'),
(17, 'path_loaded', 'Loaded: C2 to G5', '2025-03-28 00:19:48', '::1', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36'),
(18, 'path_found', 'A2 -> B2 -> C2 -> D2 -> E2 -> E3 -> E4 -> F4 -> G4 -> G5', '2025-03-28 00:21:23', '::1', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `building`
--
ALTER TABLE `building`
  ADD PRIMARY KEY (`building_id`);

--
-- Indexes for table `classroom`
--
ALTER TABLE `classroom`
  ADD PRIMARY KEY (`classroom_id`),
  ADD KEY `building_id` (`building_id`);

--
-- Indexes for table `favorite_routes`
--
ALTER TABLE `favorite_routes`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `user_activity`
--
ALTER TABLE `user_activity`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `building`
--
ALTER TABLE `building`
  MODIFY `building_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `classroom`
--
ALTER TABLE `classroom`
  MODIFY `classroom_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=47;

--
-- AUTO_INCREMENT for table `favorite_routes`
--
ALTER TABLE `favorite_routes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `user_activity`
--
ALTER TABLE `user_activity`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `classroom`
--
ALTER TABLE `classroom`
  ADD CONSTRAINT `classroom_ibfk_1` FOREIGN KEY (`building_id`) REFERENCES `building` (`building_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
